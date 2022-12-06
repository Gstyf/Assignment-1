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
				CurrentGameState.CurrentLevel.ResetScore();
				}
			break;
			}
		
		case (GameScreen::GAMEPLAY):
			{
			CurrentGameState.CurrentLevel.update();
			break;
			}
		}


	RenderGraphics();
	}