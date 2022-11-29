#pragma once
#include <vector>
#include "Levels.h"

enum struct GameScreen { TITLE = 0, GAMEPLAY, GAMEOVER, ENDING };

struct GameState {
	GameScreen CurrentScreen;
	std::vector<Level> Levels;
	int CurrentLevel;
	};

