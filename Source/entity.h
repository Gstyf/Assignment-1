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
	Vector2i position = { 0,0 };
	EntityType entityType;

	Vector2i posOffset = { 0, 0 };
	Vector2i size = { 0, 0 };
	int rsize = 10;
};

struct EntityDescription
{
	Vector2i posOffset = { 0, 0 };
	Vector2i size = { 0, 0 };
	int rsize = 10;
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