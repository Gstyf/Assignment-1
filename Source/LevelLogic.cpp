#include "ResourceManager.h"
#include "Level.h"
#include <assert.h>

/* Jonathan Hedvall
This levellogic is the 2nd iteration of the system. I wanted to handle it through the use of a gridsystem to make the code both faster and easier to write/handle.
From a peformance perspective I belive that constructing one grid for each level on demand is paid tenfold in the effectiveness it gives, for example I can simply use indecies when accesing-
-instead of having to search through the entire array to find a single entity. The previous option could be made more effective through the use of a hashmap tailored specifically to this situation-
-but I would rather work with a grid system. The reason the gridsystem is not built from the beginning is the preserve the benefits of a list system of storing entities, namely it's ease of handle outside-
-of the movement based code (graphics and initialization for example).

The "grid" has two layers and is a simple array which behaves as a grid through the use of translate functions, it contains a GridComponent in each cell which carries two entity pointers. 
This serves to create a two layered grid where different logic can be handled based on the grid. Objects on layer0 can have objects on top of them (such as a switch) wheras objects in layer1 can't.

The movement logic itself is very simple and can be described as this logic system:

1: Check future position for object
	if null move there and return true
	else if movable object is there do 1: on said object
		if return true : move there and return true

	if there is an immovable object there return false

The reason I choose this was beacuse I belive it is the most effective way to interact with my grid system.

This file also handles the winlogic and it simply checks each time the player moves if all switches have boxes on top of it.
By using this system I can use the much more effective entitylayer0 vector instead of having to go through the grid, the disadvantages of this is that it's hard to interact and play conditional code in on switch cases
for example playing sounds when a box is moved over a switch. 
*/


//Grid Managment
int EntityGrid::TranslateTo1D(int XVal, int YVal) //Translates 2D coordinates into 1D ones
	{
	return (XVal + YVal * XTILECOUNT);
	}


Entity* EntityGrid::GetEntityAtPos(int XIndex, int YIndex, int Layer) //Gets an entity at a position by pointer, by using the layer array on a gridcomponent
	{
	return ((GetComponentAtPos(XIndex, YIndex)->Layers[Layer]));
	}


GridComponent* EntityGrid::GetComponentAtPos(int XIndex, int YIndex) //Gets a gridcomponent at a position by pointer
	{
	int Index = TranslateTo1D(XIndex, YIndex);
	GridComponent* ComponentToReturn = &InternalArray[Index];
	return (ComponentToReturn);
	}


void EntityGrid::SetEntityAtPos(int XIndex, int YIndex, Entity* EntityToSet, int Layer) //Moves an entity to a position
	{
	EntityToSet->position.x = XIndex;
	EntityToSet->position.y = YIndex;
	InternalArray[TranslateTo1D(XIndex, YIndex)].Layers[Layer] = EntityToSet;
	}


void EntityGrid::ClearEntityAtPos(int XIndex, int YIndex, int Layer) //Sets the entitypointer at an index to nullptr
	{
	InternalArray[TranslateTo1D(XIndex, YIndex)].Layers[Layer] = nullptr;
	}


void EntityGrid::SetGridLayerToVector(int Layer, std::vector<Entity>& LevelVector) //Sets all the content of a vector to positions on a layer
	{
	for (int i = 0; i < LevelVector.size(); i++)
		{
		Entity* TempEntity = &LevelVector[i];
		InternalArray[TranslateTo1D(TempEntity->position.x, TempEntity->position.y)].Layers[Layer] = TempEntity;
		std::cout << TranslateTo1D(TempEntity->position.x, TempEntity->position.y) << "\n";
		}
	}


//Main Logic
Vector2i Level::CreateMovementVector() //Get controls
	{
	int XMVM = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int YMVM = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);
	return Vector2i{ XMVM, YMVM };
	}


void Level::CommitMovement(Vector2i& MovementVector, int& XVal, int& YVal) //Set future position to self then remove current position
	{
	Entity* EntityToSet = LevelGrid.GetEntityAtPos(XVal, YVal, 1);
	LevelGrid.SetEntityAtPos(XVal + MovementVector.x, YVal + MovementVector.y, EntityToSet, 1);
	LevelGrid.ClearEntityAtPos(XVal, YVal, 1);
	}


bool Level::MoveEntity(Vector2i& MovementVector, int XVal, int YVal, bool CanPush) //Reference fucks everything up, why? int& XVal
	{
	Entity* FuturePosEntity = LevelGrid.GetEntityAtPos(XVal + MovementVector.x, YVal + MovementVector.y, 1);
	
	if (FuturePosEntity == nullptr) //No entity 
		{
		CommitMovement(MovementVector, XVal, YVal);
		return (true);
		}
		
	if (FuturePosEntity->entityDescription->IsMovable) //Movable entity
		{
		if (CanPush == false) { return (false); }

		if (MoveEntity(MovementVector, FuturePosEntity->position.x, FuturePosEntity->position.y, false))
			{
			StopSoundMulti();
			PlaySoundMulti(Resources::Sounds[1]); //Boxmove sound
			CommitMovement(MovementVector, XVal, YVal);
			return (true);
			}
		else { return (false); }
		}


	//Unmovable entity
	StopSoundMulti();
	PlaySoundMulti(Resources::Sounds[0]); //Collision sound
	return (false); 
	}


bool Level::CheckWin() //Check if there is a box above each switch 
	{
	for (int i = 0; i < EntetiesLayer0.size(); i++)
		{
		Entity TempEntity = EntetiesLayer0[i]; 
		if (TempEntity.entityDescription->IsSwitch)
			{
			Entity* EntityToCheck = LevelGrid.GetEntityAtPos(TempEntity.position.x, TempEntity.position.y, 1);
			if (EntityToCheck == nullptr) { return (false); }
			if (EntityToCheck->entityDescription->IsBox == false) { return (false); }
			}
		}
	return (true);
	}


void Level::Update() //Called each frame, main for logic
	{
	Vector2i MovementVector = CreateMovementVector();

	if ((MovementVector.x != 0) || (MovementVector.y != 0))
		{
		if (MoveEntity(MovementVector, PlayerPosition.x, PlayerPosition.y, true))
			{
			PlayerPosition += MovementVector;
			}

		Win = CheckWin(); 
		}
	}


void Level::ResetLevel() //Called at each instansiation of level
	{
	Win = false;
	LevelGrid.SetGridLayerToVector(0, EntetiesLayer0); 
	LevelGrid.SetGridLayerToVector(1, EntetiesLayer1);
	}