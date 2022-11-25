#include <vector>
#include "myMath.h"
#include "Levels.h"

void Level::render()
{
	for (Entity& e : entities)
	{
		switch (e.entityType)
		{
		case EntityType::PLAYER:
		{
			DrawCircle(e.position.x*64 + 32, e.position.y*64 + 32, 10, RAYWHITE);
		}
			break;
		case EntityType::WALL:
		{
			DrawRectangle(e.position.x * 64, e.position.y * 64, 64, 64, RED);
		}
			break;
		case EntityType::BOX:
		{
			DrawRectangle(e.position.x * 64 + 8, e.position.y * 64 + 8, 48, 48, BLUE);
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