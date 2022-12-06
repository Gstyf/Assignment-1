#include "Game.h"


void GameManager::UpdateGameLoop() //Handles all scene and level logic and then calls the renderer
	{
	GameState* CGS = &CurrentGameState;

	switch (CGS->CurrentScreen) //We should implement an eventsystem and thereby avoid this, for example how is the current level changed in the levelchanger?
		{
		case (GameScreen::TITLE):
			{
			if (IsKeyDown(KEY_SPACE)) 
				{ 
				CGS->CurrentScreen = GameScreen::GAMEPLAY; 
				CGS->CurrentLevel.ResetScore();
				}
			break;
			}
		
		case (GameScreen::GAMEPLAY):
			{
			CGS->CurrentLevel.update();
			break;
			}
		}


	RenderGraphics();
	}