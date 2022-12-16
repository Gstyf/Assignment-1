#pragma once
#include <vector>
#include "Level.h"
#include "ResourceManager.h"

/* Jonathan Hedvall
This is structured to help facilitate the gamestate system, see comments in Main.cpp and Game.cpp for more info
*/

enum struct GameScreen { TITLE = 0, GAMEPLAY, GAMEOVER, ENDING, LEVELSELECT };


struct GameState {
	GameScreen CurrentScreen;
	int CurrentLevelIndex;
	Level CurrentLevel;
	};


struct GameManager {
	GameState CurrentGameState;

	void InstanciateCurrentLevel();
	void UpdateGameLoop();
	void RenderGraphics();
	};
