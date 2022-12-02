#include <vector>
#include "myMath.h"
#include "Levels.h"
#include "Resources.h"



void Level::render(Textures & textures)
{
	for (Entity& e : entities)
	{
		switch (e.entityType)
		{
		case EntityType::PLAYER:
		{
			//DrawRectangle(e.position.x*64 +10, e.position.y*64 +10 ,10, 10, RAYWHITE);
			DrawTexture(textures.Player, e.position.x * 64, e.position.y * 64, RAYWHITE);
		}
			break;
		case EntityType::WALL:
		{
			DrawRectangle(e.position.x * 64, e.position.y * 64, 64, 64, RED);

			DrawTexture(textures.Wall, e.position.x * 64, e.position.y * 64, WHITE);
		}
			break;
		case EntityType::BOX:
		{
			//DrawRectangle(e.position.x * 64, e.position.y * 64, 48, 48, BLUE);
			DrawTexture(textures.Box, e.position.x * 64, e.position.y * 64, WHITE);
		} 
			break;
		case EntityType::SWITCH:
		{
			DrawRectangle(e.position.x * 64, e.position.y * 64, 64, 64, YELLOW);
			DrawTexture(textures.Switch,e.position.x * 64, e.position.y * 64, YELLOW);
		}
			break;
		}
	}
}