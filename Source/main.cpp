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
		Entity { Vector2i {6,2}, EntityType {EntityType::SWITCH}},
		Entity { Vector2i {7,2}, EntityType {EntityType::SWITCH}},     //switch
		Entity { Vector2i {8,2}, EntityType {EntityType::SWITCH}},
		Entity { Vector2i {6,1}, EntityType {EntityType::WALL} }, //wall
		Entity { Vector2i {7,1}, EntityType {EntityType::WALL} },
		Entity { Vector2i {8,1}, EntityType {EntityType::WALL} },
		Entity { Vector2i {5,2}, EntityType {EntityType::WALL} },
		Entity { Vector2i {5,3}, EntityType {EntityType::WALL} },
		Entity { Vector2i {9,2}, EntityType {EntityType::WALL} },
		Entity { Vector2i {9,3}, EntityType {EntityType::WALL} },
		Entity { Vector2i {10,4}, EntityType {EntityType::WALL} },
		Entity { Vector2i {11,4}, EntityType {EntityType::WALL} },
		Entity { Vector2i {4,4}, EntityType {EntityType::WALL} },
		Entity { Vector2i {3,4}, EntityType {EntityType::WALL} },
		Entity { Vector2i {2,5}, EntityType {EntityType::WALL} },
		Entity { Vector2i {2,6}, EntityType {EntityType::WALL} },
		Entity { Vector2i {2,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {3,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {4,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {5,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {6,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {7,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {8,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {9,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {10,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {11,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {12,7}, EntityType {EntityType::WALL} },
		Entity { Vector2i {12,6}, EntityType {EntityType::WALL} },
		Entity { Vector2i {12,5}, EntityType {EntityType::WALL} },
		Entity { Vector2i {4,5}, EntityType {EntityType::BOX} }, //box
		Entity { Vector2i {6,5}, EntityType {EntityType::BOX} },
		Entity { Vector2i {10,5}, EntityType {EntityType::BOX} },}
	};

	
int main(void)
	{
	// Initialization
	const int screenWidth = 896;
	const int screenHeight = 512;


	GameState GSMain = { GameScreen::TITLE, std::vector<Level> {LevelTest}, 0 }; //PLayer is Entity 0

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60); 

	GSMain.gametextures.Wall = LoadTexture("./wall.png");
	GSMain.gametextures.Box = LoadTexture("./box.png");
	GSMain.gametextures.Player = LoadTexture("./player.png");
	GSMain.gametextures.Switch = LoadTexture("./switch.png");

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
					DrawText("R TO RESET", 650, 40, 30, RAYWHITE);

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