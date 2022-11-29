#pragma once
#include <vector>
#include "Levels.h"
#include "Resources.h"

enum struct GameScreen { TITLE = 0, GAMEPLAY, GAMEOVER, ENDING };



struct GameState {
	GameScreen CurrentScreen;
	std::vector<Level> Levels;
	int CurrentLevel;

	Textures gametextures;

	};



