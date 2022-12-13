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
	bool IsMovable;
	bool IsSwitch;
	};

struct EntityDescription
{
	bool Movable = false;                   // the properties of the entities
	int Textures = {};
	char inlevelfile = 0;

};
