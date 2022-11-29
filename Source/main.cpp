#include "Game.h"
#include "Level.h"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"
#include <iostream>

	
int main(void)
	{
	// Initialization
	const int screenWidth = 800;
	const int screenHeight = 440;

	Resources::LoadResources();

	GameState GSMain = { GameScreen::TITLE, 0}; //PLayer is Entity 0

	Level CurrentLevel = Resources::Levels[GSMain.CurrentLevel]; //TEMPORARY

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60); 

	// Main game loop
	try
		{
		while (!WindowShouldClose())    
			{
			if (IsKeyPressed(KEY_R))
				{
				GSMain.CurrentScreen = GameScreen::GAMEPLAY;
				CurrentLevel = Resources::Levels[GSMain.CurrentLevel];
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
					Resources::Levels[GSMain.CurrentLevel].update();
					

					//Rendering
					BeginDrawing();

					ClearBackground(BLACK);

					//IMPLEMENT RENDERING HERE:
					Resources::Levels[GSMain.CurrentLevel].render();
					DrawText("R TO RESET", 550, 400, 30, RAYWHITE);

					EndDrawing();


					if (Resources::Levels[GSMain.CurrentLevel].CONTINUE) { GSMain.CurrentScreen = GameScreen::ENDING; }
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