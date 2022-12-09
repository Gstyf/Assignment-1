#include "ResourceManager.h"
#include "Level.h"
#include "CONSTANTS.h"

//Grid
int TranslateTo1D(int XVal, int YVal) //Translates 2D coordinates into 1D ones
	{
	return (XVal + YVal * XTILECOUNT);
	}


Entity* EntityGrid::GetEntityAtPos(int XIndex, int YIndex, int Layer) //Gets an entity at a position by pointer
	{
	return ((GetComponentAtPos(XIndex, YIndex)->Layers[Layer]));
	}


GridComponent* EntityGrid::GetComponentAtPos(int XIndex, int YIndex) //Gets a gridcomponent at a position by pointer
	{
	return (&(InternalArray[TranslateTo1D(XIndex, YIndex)]));
	}


void EntityGrid::SetEntityAtPos(int XIndex, int YIndex, Entity* EntityToSet, int Layer) //Moves an entity to a position
	{
	EntityToSet->position.x = XIndex;
	EntityToSet->position.y = YIndex;
	InternalArray[TranslateTo1D(XIndex, YIndex)].Layers[Layer] = EntityToSet;
	}


void EntityGrid::SetGridLayerToVector(int Layer, std::vector<Entity> LevelVector) //Sets all the content of a vector to positions on a layer
	{
	for (int i = 0; i < LevelVector.size(); i++)
		{
		Entity* TempEntity = &LevelVector[i];
		InternalArray[TranslateTo1D(TempEntity->position.x, TempEntity->position.y)].Layers[Layer] = TempEntity;
		}
	}


//Movement
Vector2i Level::CreateMovementVector() //Get controls
	{
	int XMVM = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int YMVM = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);
	return Vector2i{ XMVM, YMVM };
	}


bool Level::MoveEntity(Vector2i MovementVector, int XVal, int YVal, bool CanPush) 
	{
	Entity* FuturePosEntity = LevelGrid.GetEntityAtPos(XVal, YVal, 1);
	
	if (FuturePosEntity != nullptr) //No entity 
		{
		LevelGrid.SetEntityAtPos(XVal + MovementVector.x, YVal + MovementVector.y, LevelGrid.GetEntityAtPos(XVal, YVal, 1), 1);
		LevelGrid.GetComponentAtPos(XVal, YVal)->Layers[1] = nullptr;
		return (true);
		}
		
			
	if (FuturePosEntity->IsMovable) //Movable entity
		{
		if (CanPush == false) { return (false); }

		if (MoveEntity(MovementVector, XVal, YVal, false))
			{
			LevelGrid.SetEntityAtPos(XVal + MovementVector.x, YVal + MovementVector.y, LevelGrid.GetEntityAtPos(XVal, YVal, 1), 1);
			return (true);
			}
		else { return (false); }
		}


	return (false); //Unmovable entity
	}



//Question: if check a index of a thing that has been moved is it nullptr?

bool Level::CheckWin() //Check if there is a box at each switch
	{
	for (int i = 0; i < EntetiesLayer0.size(); i++)
		{
		if (EntetiesLayer0[i])
		}
	}


void Level::Update2()
	{
	MoveEntity(CreateMovementVector(), PlayerPosition.x, PlayerPosition.y, true);
	}


void Level::ResetScore() //SHOULD BE RESETLEVEL LATER ON, ONLY THIS TO WORK
	{
	//LevelGrid.SetGridLayerToVector(0, EntitesLayer0); NO LOGIC IS APPLIED TO THE FIRST LAYER
	LevelGrid.SetGridLayerToVector(1, EntetiesLayer1);
	}