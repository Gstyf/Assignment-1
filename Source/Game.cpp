#include "Game.h"


void GameManager::InstanciateCurrentLevel()
	{
	CurrentGameState.CurrentLevel = Resources::Levels[CurrentGameState.CurrentLevelIndex];
	CurrentGameState.CurrentLevel.ResetLevel();
	}


void GameManager::UpdateGameLoop() //Handles all scene and level logic and then calls the renderer
	{
	switch (CurrentGameState.CurrentScreen) 
		{
		case (GameScreen::TITLE):
			{
			if (IsKeyDown(KEY_SPACE)) //When space is pressed start the game
				{ 
				CurrentGameState.CurrentScreen = GameScreen::GAMEPLAY;
				InstanciateCurrentLevel();
				}
			break;
			}

		case (GameScreen::ENDING):
			{
			if (IsKeyDown(KEY_SPACE)) //When space is pressed go to next level
				{
				if (CurrentGameState.CurrentLevelIndex >= Resources::Levels.size() - 1) { CurrentGameState.CurrentLevelIndex = 0; }
				else { CurrentGameState.CurrentLevelIndex++; }

				CurrentGameState.CurrentScreen = GameScreen::GAMEPLAY;
				InstanciateCurrentLevel();
				}
			break;
			}
		
		case (GameScreen::GAMEPLAY):
			{
			if (IsKeyDown(KEY_A)) { CurrentGameState.CurrentScreen = GameScreen::ENDING; } //Skip Level
			if (IsKeyDown(KEY_R)) { InstanciateCurrentLevel();} //Reload level
			
			CurrentGameState.CurrentLevel.Update();
			
			if (CurrentGameState.CurrentLevel.Win) { CurrentGameState.CurrentScreen = GameScreen::ENDING; } //Win
			break;
			}
		}

	RenderGraphics();
	}