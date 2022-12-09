#pragma once
#include <vector>
#include "myMath.h"
#include "entity.h"

//Grid, construct a grid with two layers
struct GridComponent {
	Entity Layers[2];
	};


struct EntityGrid {
	GridComponent InternalArray[(XTILECOUNT * YTILECOUNT)]; //Create grid of size Xcells * Ycells
	GridComponent GetAtPos(int XIndex, int YIndex);
	void SetEntityAtPos(int XIndex, int YIndex, Entity EntityToSet, int Layer);
	void SetGridLayerToVector(int Layer, std::vector<Entity> LevelVector); //Sets all the content of a vector to positions on a layer
	};


struct Level
	{
	std::vector<Entity> entities = {};
	std::vector<Entity> EntitesLayer0 = {};
	std::vector<Entity> EntitesLayer1 = {};

	EntityGrid LevelGrid;

	//Logic
	void ResetScore();
	Vector2i CreateMovementVector();
	Entity* GetEntityByPosition(Vector2i Position);
	bool IsEntityTypeAtPosition(Vector2i Position, EntityType Type);
	bool MoveBox(Entity* Box, Vector2i MovementVector);
	bool ScoutMovement(Vector2i Position, Vector2i MovementVector);
	void MovePlayer(Vector2i MovementVector);

	int RequiredScore = 0;
	int CurrentScore = 0;

	Vector2i PlayerPosition;

	void update();
	};

constexpr Entity NullEntity = { Vector2i {-1, -1}, EntityType {EntityType::NONE} };

