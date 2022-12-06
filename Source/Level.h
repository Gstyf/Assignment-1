#pragma once
#include <vector>
#include "myMath.h"
#include "entity.h"


struct Level
{
	std::vector<Entity> entities = {};

	//LogicFunctions
	void ResetScore();
	Vector2i CreateMovementVector();
	Entity* GetEntityByPosition(Vector2i Position);
	bool IsEntityTypeAtPosition(Vector2i Position, EntityType Type);
	bool MoveBox(Entity* Box, Vector2i MovementVector);
	bool ScoutMovement(Vector2i Position, Vector2i MovementVector);
	void MovePlayer(Vector2i MovementVector);

	int RequiredScore = 0;
	int CurrentScore = 0;

	void render();
	void update();
};

constexpr Entity NullEntity = { Vector2i {-1, -1}, EntityType {EntityType::NONE} };

