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
	bool IsPlayer;
	};
