#pragma once
#include <vector>
#include "Level.h"
#include "ResourceManager.h"

/*
	Code created by Gustaf & Jonathan
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
