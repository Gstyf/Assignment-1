#include <vector>
#include "Levels.h"
#include "myMath.h"


Vector2i CreateMovementVector()
	{
	int XMVM = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int YMVM = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);
	return Vector2i{ XMVM, YMVM };
	}


bool OccupiedByBox(Vector2i Position)
	{
	for (int i = 0; i < BoxVector.size(); i++)
		{
		if (BoxVector[i] == Position) { return (true); }
		}
	return (false);
	}


bool OccupiedByWall(Vector2i Position)
	{
	for (int i = 0; i < WallVector.size(); i++)
		{
		if (WallVector[i] == Position) { return (true); }
		}
	return (false);
	}


Vector2i* Level::GetBox(Vector2i Position)
	{
	for (int i = 0; i < BoxVector.size(); i++)
		{
		if (BoxVector[i] == Position) { return (&(BoxVector)[i]); }
		}
	return (nullptr);
	}


void Level::MovePlayer(Vector2i MovementVector)
	{
	Vector2i FutureMovement = entities[0].position + MovementVector;
	/*if (OccupiedByBox(FutureMovement, MainLevel->Boxes))
		{
		Vector2i FutureBoxMovement = FutureMovement + MovementVector;
		if (OccupiedByWall(FutureBoxMovement, MainLevel->Boxes) == false)
			{
			Vector2i* BoxToMove = GetBox(FutureBoxMovement, MainLevel->Boxes);
			BoxToMove->x = FutureBoxMovement.x;
			BoxToMove->y = FutureBoxMovement.y;
			MainLevel->entities[0].position = FutureMovement;
			}
		}
	else if (OccupiedByWall(FutureMovement, MainLevel->Walls) == false)
		{
		MainLevel->entities[0].position = FutureMovement;
		}*/
	entities[0].position = FutureMovement;
	}


void Level::update()
	{
	MovePlayer(CreateMovementVector());
	}