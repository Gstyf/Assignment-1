#pragma once
#include <vector>
#include "myMath.h"
#include "entity.h"

struct Level
{
	std::vector<Entity> entities = {};
	std::vector<Vector2i> Walls;
	std::vector<Vector2i> Boxes;
	std::vector<Vector2i> WinPoints;

	void render();
};

//void Level::render();

/*
Level LevelTest{
	Vector2i {5,5}, //PlayerPos
	std::vector<Vector2i> { Vector2i {2,2}, Vector2i {2,3}, Vector2i {3,2}, Vector2i {1,2}}, //Walls
	std::vector<Vector2i> { Vector2i {6,6}}, //Boxes
	std::vector<Vector2i> { Vector2i {4,4}} //WinPoints
	};
	*/