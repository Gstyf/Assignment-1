#include <vector>
#include "Levels.h"
#include "myMath.h"


Vector2i Level::CreateMovementVector()
	{
	int XMVM = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int YMVM = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);
	return Vector2i{ XMVM, YMVM };
	}


Entity* Level::GetEntityByPosition(Vector2i Position)
	{
	Entity* EntityAtPosition = nullptr;

	for (int i = 1; i < entities.size(); i++)
		{
		if (entities[i].position == Position)
			{
			EntityAtPosition = &entities[i];
			break;
			}
		}

	return (EntityAtPosition);
	}


bool Level::MoveBox(Entity* Box, Vector2i MovementVector)
	{
	Entity* EntityAtPosition = GetEntityByPosition(Box->position + MovementVector);
	
	if (EntityAtPosition == nullptr) 
		{ 
		Box->position = Box->position + MovementVector;
		return (true);
		}
	else
		{
		switch (EntityAtPosition->entityType)
			{
			case (EntityType::WALL):
			case (EntityType::BOX):
				{
				return (false);
				}

			case (EntityType::SWITCH): //WIN
				{
				CONTINUE = true;
				Box->position = Box->position + MovementVector;
				return (true);
				}
			}
		}

	throw(101);
	}


bool Level::ScoutMovement(Vector2i Position, Vector2i MovementVector)
	{
	Entity* EntityAtPosition = GetEntityByPosition(Position);

	if (EntityAtPosition == nullptr) { return(true); }
	else
		{
		switch (EntityAtPosition->entityType)
			{
			case (EntityType::SWITCH):
				{
				return (true);
				}

			case (EntityType::WALL):
				{
				return (false);
				}

			case (EntityType::BOX):
				{
				return (MoveBox(EntityAtPosition, MovementVector));
				}
			}
		}

	throw(101);
	}


void Level::MovePlayer(Vector2i MovementVector)
	{
	Vector2i FutureMovement = entities[0].position + MovementVector;
	if (ScoutMovement(FutureMovement, MovementVector)) { entities[0].position = FutureMovement; }
	}


void Level::update()
	{
	MovePlayer(CreateMovementVector());
	}