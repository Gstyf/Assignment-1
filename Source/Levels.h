#pragma once
#include <vector>
#include "myMath.h"
#include "entity.h"
#include "Resources.h"

struct Level
{
	std::vector<Entity> entities = {};

	//LogicFunctions
	Vector2i CreateMovementVector();
	Entity* GetEntityByPosition(Vector2i Position);
	bool MoveBox(Entity* Box, Vector2i MovementVector);
	bool ScoutMovement(Vector2i Position, Vector2i MovementVector);
	void MovePlayer(Vector2i MovementVector);

	bool CONTINUE;

	void render(Textures& textures);
	void update();
};

constexpr Entity NullEntity = { Vector2i {-1, -1}, EntityType {EntityType::NONE} };

