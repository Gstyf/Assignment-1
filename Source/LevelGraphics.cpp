#include <vector>
#include "myMath.h"
#include "Level.h"
#include "ResourceManager.h"



void Level::render()
{
	for (Entity& e : entities)
	{
		switch (e.entityType)
		{
		case EntityType::PLAYER:
		{
			DrawTexture(Resources::Textures[0], e.position.x * 64, e.position.y * 64 + 24, RAYWHITE);
		}
			break;
		case EntityType::WALL:
		{

			DrawTexture(Resources::Textures[1], e.position.x * 64, e.position.y * 64, WHITE);
		}
			break;
		case EntityType::BOX:
		{
			DrawTexture(Resources::Textures[2], e.position.x * 64, e.position.y * 64 + 8, WHITE);
		} 
			break;
		case EntityType::SWITCH:
		{
			DrawCircle(e.position.x * 64, e.position.y * 64, 10, YELLOW);
		}
			break;
		}
	}
}