#include "Game.h"
#include "Levels.h"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"


Level LevelTest
	{
		std::vector<Entity> {
		Entity { Vector2i {5,5}, EntityType {EntityType::PLAYER} }, //PlayerPos
		Entity { Vector2i {1,0}, EntityType {EntityType::WALL} }, //wall
		Entity { Vector2i {2,0}, EntityType {EntityType::WALL} },
		Entity { Vector2i {3,0}, EntityType {EntityType::WALL} },
		Entity { Vector2i {3,3}, EntityType {EntityType::BOX} }, //box
		Entity { Vector2i {4,4}, EntityType {EntityType::SWITCH} }, //switch
		}
	};

	
int main(void)
	{
	// Initialization
	const int screenWidth = 800;
	const int screenHeight = 440;


	GameState GSMain = { GameScreen::TITLE, std::vector<Level> {LevelTest}, 0 }; //PLayer is Entity 0

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);       



	// Main game loop
	while (!WindowShouldClose())    
		{
		switch (GSMain.CurrentScreen)
			{
			case GameScreen::TITLE:
				{
				BeginDrawing();

				ClearBackground(BLACK);

				DrawText("Welcome! You are about to play a shitty game by team 7.", 100, 200, 20, RAYWHITE);
				DrawText("Press a key to get to next screen.", 100, 300, 10, RAYWHITE);


				EndDrawing();

				if (IsKeyPressed(KEY_SPACE)) { GSMain.CurrentScreen = GameScreen::GAMEPLAY; }
				
				break;
				}

			case GameScreen::GAMEPLAY:
				{
				//Logic
				GSMain.Levels[GSMain.CurrentLevel].update();
				

				//Rendering
				BeginDrawing();

				ClearBackground(BLACK);

				//IMPLEMENT RENDERING HERE:
				GSMain.Levels[GSMain.CurrentLevel].render();

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

	CloseWindow(); // Close window and OpenGL context

	return 0;
	}