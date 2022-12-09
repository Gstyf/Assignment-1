#include "ResourceManager.h"
#include "Level.h"
#include "CONSTANTS.h"

//Grid
GridComponent EntityGrid::GetAtPos(int XIndex, int YIndex)
	{
	return InternalArray[XIndex + YIndex * XTILECOUNT];
	}


void EntityGrid::SetEntityAtPos(int XIndex, int YIndex, Entity EntityToSet, int Layer)
	{
	InternalArray[XIndex + YIndex * XTILECOUNT].Layers[Layer] = EntityToSet;
	}


void EntityGrid::SetGridLayerToVector(int Layer, std::vector<Entity> LevelVector)
	{
	for (int i = 0; i < LevelVector.size(); i++)
		{
		Entity TempEntity = LevelVector[i];
		this->SetEntityAtPos(TempEntity.position.x, TempEntity.position.y, TempEntity, Layer);
		}
	}


//Movement
Vector2i GetPlayerPositon()
	{

	}

Vector2i Level::CreateMovementVector()
	{
	int XMVM = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int YMVM = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);
	return Vector2i{ XMVM, YMVM };
	}


void Update()
	{

	}


void Level::ResetScore() //SHOULD BE RESETLEVEL LATER ON, ONLY THIS TO WORK
	{

	}