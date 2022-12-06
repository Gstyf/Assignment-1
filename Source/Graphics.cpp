#include <vector>
#include "myMath.h"
#include "Level.h"
#include "ResourceManager.h"
#include "Game.h"

void GameManager::RenderGraphics()
	{
	BeginDrawing();
	ClearBackground(BLACK);

	switch (CurrentGameState.CurrentScreen)
		{ 
		case (GameScreen::ENDING):
			{
			DrawText("YOU WIN", WindowWidth / 2 - 32 * 8, WindowHeight / 2 - 64, 32, RAYWHITE);
			DrawText("PRESS SPACE TO GO TO NEXT LEVEL", WindowWidth / 2 - 32 * 8, WindowHeight / 2 - 32, 32, RAYWHITE);
			break;
			}

		case (GameScreen::TITLE):
			{
			DrawText("PRESS SPACE TO START", WindowWidth / 2 - 32*6, WindowHeight / 2 - 32, 32, RAYWHITE);
			break;
			}

		case (GameScreen::GAMEPLAY):
			{
			for (Entity& e : CurrentGameState.CurrentLevel.entities)
				{
				switch (e.entityType)
					{
					case EntityType::PLAYER:
						{
						DrawTexture(Resources::Textures[0], e.position.x * 64, e.position.y * 64, RAYWHITE);
						}
						break;
					case EntityType::WALL:
						{

						DrawTexture(Resources::Textures[1], e.position.x * 64, e.position.y * 64, WHITE);
						}
						break;
					case EntityType::BOX:
						{
						DrawTexture(Resources::Textures[2], e.position.x * 64, e.position.y * 64, WHITE);
						}
						break;
					case EntityType::SWITCH:
						{
						DrawTexture(Resources::Textures[3], e.position.x * 64, e.position.y * 64, WHITE);
						}
						break;
					}
				}
			}
		}

	EndDrawing();
	}

