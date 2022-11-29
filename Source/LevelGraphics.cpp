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
			DrawCircle(e.position.x*64 + 32, e.position.y*64 + 32, 10, RAYWHITE);
			DrawTexture(textures.Player, e.position.x * 64 + 24, e.position.y * 64 + 24, RAYWHITE);
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
			DrawRectangle(e.position.x * 64 + 8, e.position.y * 64 + 8, 48, 48, BLUE);
			DrawTexture(textures.Box, e.position.x * 64 + 8, e.position.y * 64 + 8, WHITE);
		} 
			break;
		case EntityType::SWITCH:
		{
			DrawCircle(e.position.x * 64 + 32, e.position.y * 64 + 32, 10, YELLOW);
		}
			break;
		}
	}
}