#include "Game.h"
#include "Level.h"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"
#include <iostream>

	
int main(void)
	{
	// Initialization
	const int screenWidth = 896;
	const int screenHeight = 512;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	Resources::LoadResources();

	GameState GSMain = { GameScreen::TITLE, 0 }; //PLayer is Entity 0

	Level CurrentLevel = Resources::Levels[GSMain.CurrentLevelIndex]; //TEMPORARY
	CurrentLevel.ResetScore();

	SetTargetFPS(60); 

	// Main game loop
	try
		{
		while (!WindowShouldClose())    
			{
			if (IsKeyPressed(KEY_R))
				{
				GSMain.CurrentScreen = GameScreen::GAMEPLAY;
				CurrentLevel = Resources::Levels[GSMain.CurrentLevelIndex];
				CurrentLevel.ResetScore();
				}

			switch (GSMain.CurrentScreen)
				{
				case GameScreen::TITLE:
					{
					BeginDrawing();

					ClearBackground(BLACK);

					DrawText("TEAM 7.", 100, 100, 60, RAYWHITE);
					DrawText("SPACE TO CONTINUE", 100, 300, 40, RAYWHITE);

					EndDrawing();

					if (IsKeyPressed(KEY_SPACE)) { GSMain.CurrentScreen = GameScreen::GAMEPLAY; }
					
					break;
					}

				case GameScreen::GAMEPLAY:
					{
					//Logic
					CurrentLevel.update();
					

					//Rendering
					BeginDrawing();

					ClearBackground(BLACK);

					//IMPLEMENT RENDERING HERE:
					CurrentLevel.render();
					DrawText("R TO RESET", 680, 20, 30, RAYWHITE);

					EndDrawing();

					//std::cout << CurrentLevel.CurrentScore << "\n";
					if (CurrentLevel.CurrentScore >= CurrentLevel.RequiredScore) { GSMain.CurrentScreen = GameScreen::ENDING; }
					break;
					}
				
				case GameScreen::GAMEOVER:
					{
					break;
					}
				
				case GameScreen::ENDING:
					{
					ClearBackground(BLACK);

					DrawText("YOU WIN", 200, 200, 100, RAYWHITE);
					DrawText("PRESS SPACE FOR NEXT LEVEL", 170, 300, 30, RAYWHITE);

					if (IsKeyPressed(KEY_SPACE)) 
						{ 
						GSMain.CurrentScreen = GameScreen::GAMEPLAY;
					 	//int LevelCount = Resources::Levels.size();
						if (GSMain.CurrentLevelIndex >= Resources::Levels.size() - 1) { GSMain.CurrentLevelIndex = 0; }
						else { GSMain.CurrentLevelIndex++; }
						CurrentLevel = Resources::Levels[GSMain.CurrentLevelIndex];
						CurrentLevel.ResetScore();
						}
					
					EndDrawing();
					break;
					}
				}
			}
		}
	catch (int ERRORID)
		{
		std::cout << "ERROR: " << ERRORID;
		}

	CloseWindow(); // Close window and OpenGL context
	return 0;
	}