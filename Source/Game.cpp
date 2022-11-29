#include <vector>
#include "myMath.h"
#include "Levels.h"


<<<<<<< HEAD
=======
Vector2i CreateMovementVector()
	{
	int XMVM = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int YMVM = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);
	return Vector2i{ XMVM, YMVM };
	}


bool OccupiedByBox(Vector2i Position, const std::vector<Vector2i>& BoxVector)
	{
	for (int i = 0; i < BoxVector.size(); i++)
		{
		if (BoxVector[i] == Position) { return (true); }
		}
	return (false);
	}


bool OccupiedByWall(Vector2i Position, const std::vector<Vector2i>& WallVector)
	{
	for (int i = 0; i < WallVector.size(); i++)
		{
		if (WallVector[i] == Position) { return (true); }
		}
	return (false);
	}


Vector2i* GetBox(Vector2i Position, std::vector<Vector2i>& BoxVector)
	{
	for (int i = 0; i < BoxVector.size(); i++)
		{
		if (BoxVector[i] == Position) { return (&(BoxVector)[i]); }
		}
	return (nullptr);
	}


void MovePlayer(Vector2i MovementVector, Level* MainLevel) 
	{
	/*Vector2i FutureMovement = MainLevel->PlayerPos + MovementVector;
	if (OccupiedByBox(FutureMovement,  MainLevel->Boxes))
	{
		Vector2i FutureBoxMovement = FutureMovement + MovementVector;
		if (OccupiedByWall(FutureBoxMovement, MainLevel->Boxes) == false)
		{
			Vector2i* BoxToMove = GetBox(FutureBoxMovement, MainLevel->Boxes);
			BoxToMove->x = FutureBoxMovement.x;
			BoxToMove->y = FutureBoxMovement.y;
			MainLevel->PlayerPos = FutureMovement;
		}
	}
	else if (OccupiedByWall(FutureMovement, MainLevel->Walls) == false)
	{
		MainLevel->PlayerPos = FutureMovement;
	}
	MainLevel->PlayerPos = FutureMovement;*/
	}
>>>>>>> 8b70d75a682e8b4ac76aff470ef1609073535d9a
