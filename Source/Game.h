#pragma once
#include "myMath.h"
#include <vector>
#include "Levels.h"

enum struct GameScreen { TITLE = 0, GAMEPLAY, GAMEOVER, ENDING };

struct GameState {
	GameScreen CurrentScreen;
	std::vector<Level> Levels;
	int CurrentLevel;
	};

Vector2i CreateMovementVector();

bool OccupiedByBox(Vector2i Position, const std::vector<Vector2i>& BoxVector);

bool OccupiedByWall(Vector2i Position, const std::vector<Vector2i>& WallVector);

Vector2i* GetBox(Vector2i Position, std::vector<Vector2i>& BoxVector);

void MovePlayer(Vector2i MovementVector, Level* MainLevel);