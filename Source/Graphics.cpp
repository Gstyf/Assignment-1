#include <vector>
#include "myMath.h"
#include "Level.h"
#include "ResourceManager.h"
#include "Game.h"

#include "CONSTANTS.h"

/* Jonathan Hedvall
This rendersystem is designed to allow us to easily create UI and to provide an input for the entites to be rendered and effective way.
It's hard to explain "WHY" this is designed this way without going into the realm of the entities but the texture is stored in the resources to seperate it and each entity has a reference to what texture they use.
*/

void GameManager::RenderGraphics()
	{
	BeginDrawing();
	ClearBackground(BLACK);

	switch (CurrentGameState.CurrentScreen)
		{ 
		case (GameScreen::ENDING): //Render Endingscreen
			{
			DrawText("YOU WIN", WINDOWWIDTH / 2 - TILESIZEDIV2 * 8, WINDOWHEIGHT / 2 - TILESIZE, TILESIZEDIV2, RAYWHITE);
			DrawText("PRESS SPACE TO GO TO NEXT LEVEL", WINDOWWIDTH / 2 - TILESIZEDIV2 * 8, WINDOWHEIGHT / 2 - TILESIZEDIV2, TILESIZEDIV2, RAYWHITE);
			break;
			}

		case (GameScreen::TITLE): //Render Titlescreen
			{
			DrawText("TEAM 2: 'SUCKOBAN'", WINDOWWIDTH / 2 - 32*6, WINDOWHEIGHT / 3 - 32, 32, RAYWHITE);
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

