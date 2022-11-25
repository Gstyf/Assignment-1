#pragma once
#include "myMath.h"

class Entity
{
public:
	Vector2i posOffset = { 20, 20 };
	Vector2 size = { 15, 45 };
	int rsize = 10;
};

class Box : public Entity
{
public:
	Vector2i posoffset = { 40, 40 };
	Vector2 size = { 40, 40 };

	Color color = RED;

};