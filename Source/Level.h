#pragma once
#include <vector>
#include "myMath.h"
#include "entity.h"
#include "CONSTANTS.h"

//Grid, construct a grid with two layers
struct GridComponent {
	Entity* Layers[2];
	};


struct EntityGrid {
private:
	GridComponent InternalArray[(XTILECOUNT * YTILECOUNT)]; //Create grid of size Xcells * Ycells
public:
	int Size = (XTILECOUNT * YTILECOUNT);
	int TranslateTo1D(int XVal, int YVal);
	Entity* GetEntityAtPos(int XIndex, int YIndex, int Layer);
	void SetEntityAtPos(int XIndex, int YIndex, Entity* EntityToSet, int Layer);
	void SetGridLayerToVector(int Layer, std::vector<Entity> LevelVector); 
	GridComponent* GetComponentAtPos(int XIndex, int YIndex);
	};


struct Level
	{
	std::vector<Entity> entities = {};
	std::vector<Entity> EntetiesLayer0 = {};
	std::vector<Entity> EntetiesLayer1 = {};
	 
	EntityGrid LevelGrid; //!!This relies on the std::vectors not changing size!! ^

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

	void update();

	//Logic ver 2
	bool MoveEntity(Vector2i MovementVector, int Xval, int Yval, bool CanPush);
	bool CheckWin();
	void ResetLevel();

	Vector2i PlayerPosition;

	void Update2();
	};

//This doesn't work since we added a pointer to the EntityDescription, get rid of it??
//constexpr Entity NullEntity = { Vector2i {-1, -1}, EntityType {EntityType::NONE} };

