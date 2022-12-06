#include <vector>
#include "Level.h"
#include "myMath.h"
#include "ResourceManager.h"


void Level::ResetScore()
	{
	CurrentScore = 0;
	RequiredScore = 0;
	for (int i = 0; i < entities.size(); i++)
		{
		if (entities[i].entityType == EntityType::SWITCH) { RequiredScore++; }
		}
	}


Vector2i Level::CreateMovementVector()
	{
	int XMVM = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int YMVM = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);
	return Vector2i{ XMVM, YMVM };
	}


bool Level::IsEntityTypeAtPosition(Vector2i Position, EntityType Type)
	{
	for (int i = 1; i < entities.size(); i++)
		{
		if (entities[i].position == Position && entities[i].entityType == Type)
			{
			return (true);
			}
		}
	return (false);
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
	Vector2i FuturePosition = Box->position + MovementVector;
	Entity* EntityAtPosition = GetEntityByPosition(FuturePosition);
	
	if (EntityAtPosition == nullptr) 
		{ 
		Box->position = FuturePosition;
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
				if (IsEntityTypeAtPosition(Box->position, EntityType::SWITCH) == false) { CurrentScore++; }
				Box->position = FuturePosition;
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
				if (IsEntityTypeAtPosition(Position, EntityType::BOX)) { return (MoveBox(EntityAtPosition, MovementVector)); }
				else { return (true); }
				}

			case (EntityType::WALL):
				{
				return (false);
				}

			case (EntityType::BOX):
				{
				//PlaySound(Resources::Sounds[0]);
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