#pragma once
#include <vector>
#include "myMath.h"
#include "entity.h"


struct Level
{
	std::vector<Entity> entities = {};
	//std::vector<Vector2i> Walls;
	//std::vector<Vector2i> Boxes;
	//std::vector<Vector2i> WinPoints;

	void render();
};

//void Level::render();


Level LevelTest
{
	std::vector<Entity> {
	Entity { Vector2i {5,5}, EntityType {EntityType::PLAYER} }, //PlayerPos
	Entity { Vector2i {1,0}, EntityType {EntityType::WALL} }, //wall
	Entity { Vector2i {2,0}, EntityType {EntityType::WALL} },
	Entity { Vector2i {3,0}, EntityType {EntityType::WALL} },
	Entity { Vector2i {3,3}, EntityType {EntityType::BOX} }, //box
	Entity { Vector2i {4,4}, EntityType {EntityType::SWITCH} }, //switch
	}
};
