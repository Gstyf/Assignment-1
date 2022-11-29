#include "Game.h"
#include "Levels.h"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"
#include <iostream>


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

	GSMain.gametextures.Wall = LoadTexture("./wall.png");
	GSMain.gametextures.Box = LoadTexture("./box.png");
	GSMain.gametextures.Player = LoadTexture("./player.png");

	// Main game loop
	try
		{
		while (!WindowShouldClose())    
			{
			if (IsKeyPressed(KEY_R))
				{
				GSMain.CurrentScreen = GameScreen::GAMEPLAY;
				GSMain.Levels[GSMain.CurrentLevel] = LevelTest;
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
					GSMain.Levels[GSMain.CurrentLevel].update();
					

					//Rendering
					BeginDrawing();

					ClearBackground(BLACK);

					//IMPLEMENT RENDERING HERE:
					GSMain.Levels[GSMain.CurrentLevel].render(GSMain.gametextures);
					DrawText("R TO RESET", 550, 400, 30, RAYWHITE);

					EndDrawing();


					if (GSMain.Levels[GSMain.CurrentLevel].CONTINUE) { GSMain.CurrentScreen = GameScreen::ENDING; }
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