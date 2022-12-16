#include "Game.h"
/* Jonathan Hedvall
This code handles the logic and keypresses in the context of the gamestates. We needed to have this system somewhere and we thought about having a movement controller that sends events to the game manager.
The system we currently have is way lighter and less abstracted but is also more rigid in the sense that an eventsystem could support multiple things (such as seperating sound from movement and having a dedicated
soundmanager under the gamemanager which events could be sent to).
The reason the graphics are not here is so that they are properly seperated and easier to manage, for example a switch in gamestate switching code should not change how said gamestate is-
-rendered from a logic perspective.
*/



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
			
			if (CurrentGameState.CurrentLevel.Win) //Win 
				{ 
				StopSoundMulti();
				PlaySoundMulti(Resources::Sounds[2]);
				CurrentGameState.CurrentScreen = GameScreen::ENDING; 
				} 
			break;
			}
		}

	RenderGraphics();
	}