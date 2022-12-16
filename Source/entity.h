#pragma once
#include "myMath.h"
/*
	Entity.h code created by Gustaf and modified by Adarsh and Jonathan
*/
enum class EntityType
{
	NONE = 0, //We shouldn't retrieve this.
	PLAYER,
	WALL,
	BOX,
	SWITCH,
};

struct EntityDescription
{
	// the properties of the entities
	int Textures = {};
	char symbolInLevelFile = 0; // redundant??
	bool IsPlayer = false; //player only
	bool IsMovable = false; //box and player
	bool IsSwitch = false; //switches are not going to be entities in the final version
	bool IsBox = false;
};

class Entity
	{
public:
	Vector2i position; //all entities have position, so this is not removable
	EntityDescription* entityDescription; //This is the description that dictates if an object is movoable, and what texture it uses.
	};

