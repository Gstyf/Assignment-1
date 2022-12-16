#include <vector>
#include "myMath.h"
#include "Level.h"
#include "ResourceManager.h"
#include "Game.h"

#include "CONSTANTS.h"


void GameManager::RenderGraphics()
	{
	BeginDrawing();
	ClearBackground(BLACK);

	switch (CurrentGameState.CurrentScreen)
		{ 
		case (GameScreen::ENDING): //Render Endingscreen
			{
			DrawText("YOU WIN", WINDOWWIDTH / 2 - TILESIZEDIV2 * 8, WINDOWHEIGHT / 2 - TILESIZE, TILESIZEDIV2, RAYWHITE);
			DrawText("YOU WIN", WINDOWWIDTH / 2 - TILESIZEDIV2 * 8, WINDOWHEIGHT / 2 - TILESIZE, TILESIZEDIV2, RAYWHITE);
			DrawText("PRESS SPACE TO GO TO NEXT LEVEL", WINDOWWIDTH / 2 - TILESIZEDIV2 * 8, WINDOWHEIGHT / 2 - TILESIZEDIV2, TILESIZEDIV2, RAYWHITE);
			break;
			}

		case (GameScreen::TITLE): //Render Titlescreen
			{
			DrawText("PRESS SPACE TO START", WINDOWWIDTH / 2 - 32*6, WINDOWHEIGHT / 2 - 32, 32, RAYWHITE);
			break;
			}

		case (GameScreen::GAMEPLAY): //Render "Game"
			{
			std::vector<Entity> CurrentLayer = CurrentGameState.CurrentLevel.EntetiesLayer0;

			for (int i = 0; i < CurrentLayer.size(); i++)
				{
				DrawTexture
					(
					Resources::Textures[CurrentLayer[i].entityDescription->Textures], 
					CurrentLayer[i].position.x * TILESIZE,
					CurrentLayer[i].position.y * TILESIZE,
					WHITE
					);
				}

			CurrentLayer = CurrentGameState.CurrentLevel.EntetiesLayer1;

			for (int i = 0; i < CurrentLayer.size(); i++)
				{
				DrawTexture
				(
					Resources::Textures[CurrentLayer[i].entityDescription->Textures],
					CurrentLayer[i].position.x * TILESIZE,
					CurrentLayer[i].position.y * TILESIZE,
					WHITE
				);
				}
			}
		}

	EndDrawing();
	}

