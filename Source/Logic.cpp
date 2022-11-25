#include <vector>
#include "myMath.h"

//LOGIC.CPP

struct Level {
	Vector2i PlayerPos;
	std::vector<Vector2i> Walls;
	std::vector<Vector2i> Boxes;
	std::vector<Vector2i> WinPoints;
	};


Vector2i CreateMovementVector()
	{
	int XMVM = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int YMVM = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);
	return Vector2i{ XMVM, YMVM };
	}


bool OccupiedByBox(Vector2i Position, std::vector<Vector2i>* BoxVector)
	{
	for (int i = 0; i < (*BoxVector).size(); i++)
		{
		//if ((*BoxVector)[i] == Position) { return (true); }
		}
	return (false);
	}


bool OccupiedByWall(Vector2i Position, std::vector<Vector2i>* WallVector)
	{
	for (int i = 0; i < (*WallVector).size(); i++)
		{
		//if ((*WallVector)[i] == Position) { return (true); }
		}
	return (false);
	}


Vector2i* GetBox(Vector2i Position, std::vector<Vector2i>* BoxVector)
	{
	for (int i = 0; i < (*BoxVector).size(); i++)
		{
		//if ((*BoxVector)[i] == Position) { return (&(*BoxVector)[i]); }
		}
	return (nullptr);
	}


void MovePlayer(Vector2i MovementVector, Level* MainLevel) //Implement bool return
	{
	//Vector2 FutureMovement = MainLevel->PlayerPos + MovementVector;
	Vector2i FutureMovement = MainLevel->PlayerPos + MovementVector;
	/*if (OccupiedByBox(FutureMovement, &MainLevel->Boxes))
	{
		Vector2i FutureBoxMovement = FutureMovement + MovementVector;
		if (OccupiedByWall(FutureBoxMovement, &MainLevel->Boxes) == false)
		{
			Vector2i* BoxToMove = GetBox(FutureBoxMovement, &MainLevel->Boxes);
			BoxToMove->x = FutureBoxMovement.x;
			BoxToMove->y = FutureBoxMovement.y;
			MainLevel->PlayerPos = FutureMovement;
		}
	}
	else if (OccupiedByWall(FutureMovement, &MainLevel->Walls) == false)
	{
		MainLevel->PlayerPos = FutureMovement;
	}*/
	MainLevel->PlayerPos = FutureMovement;
	}