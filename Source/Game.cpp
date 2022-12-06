#include "Game.h"


void GameManager::UpdateGameLoop()
	{
	Level CurrentLevel = Resources::Levels[CurrentGameState.CurrentLevelIndex];

	if (CurrentGameState.CurrentScreen == GameScreen::GAMEPLAY) { CurrentLevel.update(); }

	RenderGraphics();
	}