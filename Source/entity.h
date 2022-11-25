#pragma once
#include "myMath.h"

enum class EntityType
{
	NONE = 0, //We shouldn't retrieve this.
	PLAYER,
	WALL,
	BOX,
	SWITCH,
};

class Entity
{
public:
	Vector2i position;
	EntityType entityType;
};


//class Box : public Entity
//{
//public:
//	Vector2i position = { 0,0 };
//	Vector2i posoffset = { 40, 40 };
//	Vector2 size = { 40, 40 };
//
//	Color color = RED;
//
//};