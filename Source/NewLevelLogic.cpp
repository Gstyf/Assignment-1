#include "ResourceManager.h"
#include "Level.h"
#include <assert.h>


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
	GridComponent ComponentToReturn = InternalArray[Index];
	return (&(ComponentToReturn));
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
		
	if (FuturePosEntity->IsMovable) //Movable entity
		{
		if (CanPush == false) { return (false); }

		if (MoveEntity(MovementVector, FuturePosEntity->position.x, FuturePosEntity->position.y, false))
			{
			CommitMovement(MovementVector, XVal, YVal);
			return (true);
			}
		else { return (false); }
		}

	//PlaySound(Resources::Sounds[0]);
	return (false); //Unmovable entity
	}


bool Level::CheckWin() //Check if there is a box above each switch 
	{
	for (int i = 0; i < EntetiesLayer0.size(); i++)
		{
		Entity TempEntity = EntetiesLayer0[i]; 
		if (TempEntity.IsSwitch)
			{
			Entity* EntityToCheck = LevelGrid.GetEntityAtPos(TempEntity.position.x, TempEntity.position.y, 1);
			if (EntityToCheck == nullptr) { return (false); }
			if (EntityToCheck->IsBox == false) { return (false); }
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