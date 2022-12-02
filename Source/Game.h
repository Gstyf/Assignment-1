#pragma once
#include <vector>
#include "Level.h"
#include "ResourceManager.h"

enum struct GameScreen { TITLE = 0, GAMEPLAY, GAMEOVER, ENDING };

struct GameState {
	GameScreen CurrentScreen;
	int CurrentLevelIndex;
	};



