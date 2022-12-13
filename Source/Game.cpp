#include "Game.h"


void GameManager::UpdateGameLoop() //Handles all scene and level logic and then calls the renderer
	{
	switch (CurrentGameState.CurrentScreen) //We should implement an eventsystem and thereby avoid this, for example how is the current level changed in the levelchanger?
		{
		case (GameScreen::TITLE):
			{
			if (IsKeyDown(KEY_SPACE)) 
				{ 
				CurrentGameState.CurrentScreen = GameScreen::GAMEPLAY;
				CurrentGameState.CurrentLevel = Resources::Levels[CurrentGameState.CurrentLevelIndex];
				CurrentGameState.CurrentLevel.ResetScore();
				}
			break;
			}

		case (GameScreen::ENDING):
			{
			if (IsKeyDown(KEY_SPACE))
				{
				if (CurrentGameState.CurrentLevelIndex >= Resources::Levels.size() - 1) { CurrentGameState.CurrentLevelIndex = 0; }
				else { CurrentGameState.CurrentLevelIndex++; }

				CurrentGameState.CurrentScreen = GameScreen::GAMEPLAY;
				CurrentGameState.CurrentLevel = Resources::Levels[CurrentGameState.CurrentLevelIndex];
				CurrentGameState.CurrentLevel.ResetScore();
				}
			break;
			}
		
		case (GameScreen::GAMEPLAY):
			{
			if (IsKeyDown(KEY_A)) { CurrentGameState.CurrentScreen = GameScreen::ENDING; }
			if (IsKeyDown(KEY_R)) {
				CurrentGameState.CurrentLevel = Resources::Levels[CurrentGameState.CurrentLevelIndex];
				CurrentGameState.CurrentLevel.ResetScore();
			}
			CurrentGameState.CurrentLevel.update();
			if (CurrentGameState.CurrentLevel.CurrentScore >= CurrentGameState.CurrentLevel.RequiredScore) { CurrentGameState.CurrentScreen = GameScreen::ENDING; }
			break;
			}
		}

	RenderGraphics();
	}