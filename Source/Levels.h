#pragma once
#include <vector>
#include "myMath.h"
#include "entity.h"
#include "Resources.h"

struct Level
{
	std::vector<Entity> entities = {};

	Vector2i CreateMovementVector();

	EntityType OccupiedByEntity(Vector2i Position);

	void MovePlayer(Vector2i MovementVector);

	void render(Textures& textures);
	void update();
};


