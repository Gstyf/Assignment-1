#pragma once
#include <vector>
#include "myMath.h"
#include "entity.h"
#include "CONSTANTS.h"

//Implementation of functions and descriptions of them are stored in NewLevelLogic.cpp


//Grid, construct a grid with two layers
struct GridComponent {
	Entity* Layers[2]{};
	};


struct EntityGrid {
private:
	GridComponent InternalArray[(XTILECOUNT * YTILECOUNT)]; //Create grid of size Xcells * Ycells
public:
	int Size = (XTILECOUNT * YTILECOUNT);
	int TranslateTo1D(int XVal, int YVal);
	Entity* GetEntityAtPos(int XIndex, int YIndex, int Layer);
	void SetEntityAtPos(int XIndex, int YIndex, Entity* EntityToSet, int Layer);
	void SetGridLayerToVector(int Layer, std::vector<Entity>& LevelVector); 
	void ClearEntityAtPos(int XIndex, int YIndex, int Layer);
	GridComponent* GetComponentAtPos(int XIndex, int YIndex);
	};


struct Level
	{
	std::vector<Entity> EntetiesLayer0 = {};
	std::vector<Entity> EntetiesLayer1 = {};
	 
	EntityGrid LevelGrid; //!!This relies on the std::vectors not changing size!! ^

	//Logic ver 2
	Vector2i CreateMovementVector();
	bool MoveEntity(Vector2i& MovementVector, int Xval, int Yval, bool CanPush);
	void CommitMovement(Vector2i& MovementVector, int& XVal, int& YVal);
	void ResetLevel();
	
	bool CheckWin();	//The reason it is structured this way is so that it does not have to check when no input is put in, 
	bool Win;			//IE. when the player is not interacting with the game
	
	Vector2i PlayerPosition;

	void Update();
	};

