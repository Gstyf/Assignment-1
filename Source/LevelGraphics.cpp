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
			break;
		case EntityType::WALL:
			break;
		case EntityType::BOX:
			break;
		case EntityType::SWITCH:
			break;
		}
	}
}