#pragma once
#include <vector>
#include "myMath.h"
#include "entity.h"

struct Level
{
	std::vector<Entity> entities = {};

	Vector2i CreateMovementVector();

	bool OccupiedByBox(Vector2i Position);

	bool OccupiedByWall(Vector2i Position);

	Vector2i* GetBox(Vector2i Position);

	void MovePlayer(Vector2i MovementVector);

	void render();
	void update();
};


/*
Level LevelTest{
	Vector2i {5,5}, //PlayerPos
	std::vector<Vector2i> { Vector2i {2,2}, Vector2i {2,3}, Vector2i {3,2}, Vector2i {1,2}}, //Walls
	std::vector<Vector2i> { Vector2i {6,6}}, //Boxes
	std::vector<Vector2i> { Vector2i {4,4}} //WinPoints
	};
	*/