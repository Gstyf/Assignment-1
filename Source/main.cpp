#include "Game.h"
#include "Levels.h"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"

	
int main(void)
	{
	// Initialization
	const int screenWidth = 800;
	const int screenHeight = 440;

	GameState GMMain = { GameScreen::TITLE, std::vector<Level> {Level{}}, 0 };

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);            


	// Main game loop
	while (!WindowShouldClose())    
		{

		switch (GMMain.CurrentScreen)
			{
			case GameScreen::TITLE:
				{
				BeginDrawing();

				ClearBackground(BLACK);

				DrawText("Welcome! You are about to play a shitty game by team 7.", 100, 200, 20, RAYWHITE);
				DrawText("Press a key to get to next screen.", 100, 300, 10, RAYWHITE);


				EndDrawing();

				if (IsKeyPressed(KEY_SPACE)) { GMMain.CurrentScreen = GameScreen::GAMEPLAY; }
				
				break;
				}

			case GameScreen::GAMEPLAY:
				{
				//Logic
				MovePlayer(CreateMovementVector(), &GMMain.Levels[GMMain.CurrentLevel]);
				

				//Rendering
				BeginDrawing();

				ClearBackground(BLACK);

				//IMPLEMENT RENDERING HERE:
				DrawCircle(GMMain.Levels[GMMain.CurrentLevel].PlayerPos.x * 64, GMMain.Levels[GMMain.CurrentLevel].PlayerPos.y * 64, 32, RAYWHITE);

				EndDrawing();

				break;
				}
			
			case GameScreen::GAMEOVER:
				{
				break;
				}
			
			case GameScreen::ENDING:
				{
				break;
				}
			}

		}

	CloseWindow();        // Close window and OpenGL context

	return 0;
	}