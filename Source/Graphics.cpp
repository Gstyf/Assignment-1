#include <vector>
#include "myMath.h"
#include "Level.h"
#include "ResourceManager.h"
#include "Game.h"
#include "CONSTANTS.h"

#include "CONSTANTS.h"

void GameManager::RenderGraphics()
	{
	BeginDrawing();
	ClearBackground(BLACK);

	switch (CurrentGameState.CurrentScreen)
		{ 
		case (GameScreen::ENDING):
			{
//<<<<<<< Updated upstream
			DrawText("YOU WIN", WINDOWWIDTH / 2 - 32 * 8, WINDOWHEIGHT / 2 - TILESIZE, 32, RAYWHITE);
//=======
			DrawText("YOU WIN", WINDOWWIDTH / 2 - 32 * 8, WINDOWHEIGHT / 2 - 64, 32, RAYWHITE);
//>>>>>>> Stashed changes
			DrawText("PRESS SPACE TO GO TO NEXT LEVEL", WINDOWWIDTH / 2 - 32 * 8, WINDOWHEIGHT / 2 - 32, 32, RAYWHITE);
			break;
			}

		case (GameScreen::TITLE):
			{
			DrawText("PRESS SPACE TO START", WINDOWWIDTH / 2 - 32*6, WINDOWHEIGHT / 2 - 32, 32, RAYWHITE);
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
						DrawTexture(Resources::Textures[0], e.position.x * TILESIZE, e.position.y * TILESIZE, RAYWHITE);
						}
						break;
					case EntityType::WALL:
						{

						DrawTexture(Resources::Textures[1], e.position.x * TILESIZE, e.position.y * TILESIZE, WHITE);
						}
						break;
					case EntityType::BOX:
						{
						DrawTexture(Resources::Textures[2], e.position.x * TILESIZE, e.position.y * TILESIZE, WHITE);
						}
						break;
					case EntityType::SWITCH:
						{
						DrawTexture(Resources::Textures[3], e.position.x * TILESIZE, e.position.y * TILESIZE, WHITE);
						}
						break;
					}
				}
			}
		}

	EndDrawing();
	}

