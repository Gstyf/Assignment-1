#include "ResourceManager.h"


std::vector<Level> Resources::Levels;
std::vector<Texture2D> Resources::Textures;
std::vector<Sound> Resources::Sounds;

std::vector<EntityDescription> Resources::entitiesdesc;

constexpr const char* TextureDirectory = "./Resources/Textures/Textures.txt";
constexpr const char* LevelDirectory = "./Resources/Levels.txt";
constexpr const char* SoundDirectory = "./Resources/Sounds/Sounds.txt";

constexpr const char* EntityDescriptionFilePath = "./Resources/Entities.txt";

void eat_space(char** cursor)
{
	while (**cursor != 0 && isspace((int) **cursor))
	{
		(*cursor)++;
	}
};

bool accept_string(char** cursors, const char* string)
{
	char* c = *cursors;

	for (;*c && *string && *c == *string; c++, string++)
	{
	}

	if (*string == 0)
	{
		*cursors = c;
		return true;
	}

	return false;
}

/*
	Code created by Adarsh
*/
void ParsEntityDescriptions(char* string)
{
	char* cursor = string;
	EntityDescription desc;
	while (true)
	{
		eat_space(&cursor);
		if (accept_string(&cursor, "entity"))
		{
			eat_space(&cursor);
			if (accept_string(&cursor, "{"))
			{
				eat_space(&cursor);
				while (!accept_string(&cursor, "}"))
				{
					eat_space(&cursor);
					if (accept_string(&cursor, "flags"))
					{
						eat_space(&cursor);
						if (accept_string(&cursor, ":"))
						{
							eat_space(&cursor);
							while (!accept_string(&cursor, ";"))
							{

								eat_space(&cursor);
								if (accept_string(&cursor, "movable"))
								{
									desc.IsMovable = true;
								}
								else if (accept_string(&cursor, "immovable"))
								{
									desc.IsMovable = false;
								}
							}
						}
					}
					eat_space(&cursor);
					if (accept_string(&cursor, "Object"))
					{
						eat_space(&cursor);
						if (accept_string(&cursor, ":"))
						{
							eat_space(&cursor);
							while (!accept_string(&cursor, ";"))
							{
								eat_space(&cursor);
								if (accept_string(&cursor, "player"))
								{
									desc.Textures = 0;
									desc.IsPlayer = true;
								}
								else if (accept_string(&cursor, "wall"))
								{
									desc.Textures = 1;
						
								}
								else if (accept_string(&cursor, "box"))
								{
									desc.Textures = 2;
									desc.IsBox = true;
									desc.IsPlayer = false;
									desc.IsSwitch = false;
									
								}
								else if (accept_string(&cursor, "switch"))
								{
									desc.Textures = 3;
									desc.IsSwitch = true;
									desc.IsPlayer = false;
									desc.IsBox = false;
								}
							}
						}
					}
					eat_space(&cursor);
					if (accept_string(&cursor, "char"))
					{
						eat_space(&cursor);
						if (accept_string(&cursor, ":"))
						{
							eat_space(&cursor);
							desc.symbolInLevelFile = *cursor;
							cursor++;

							eat_space(&cursor);
							if(!accept_string(&cursor, ";"))
							{
								// BAD
							}
						}
					}
				}
			}
			Resources::entitiesdesc.push_back(desc);
		}
		else
		{
			break;
		}
	}
	UnloadFileText(string);
}

void Resources::LoadResources()
{
	//Load Sound
	std::string ReadStringSOUND;
	std::ifstream SoundFile{ SoundDirectory };

	while (std::getline(SoundFile, ReadStringSOUND))
	{
		const char* ReadStringSOUNDchar = ReadStringSOUND.c_str();
		Sound TempSOUND = LoadSound(ReadStringSOUNDchar);
		Sounds.push_back(TempSOUND);
	}
	SoundFile.close();


	//Load Textures
	std::string ReadStringTEXTURE;
	std::ifstream TextureFile{ TextureDirectory };

	while (std::getline(TextureFile, ReadStringTEXTURE))
	{
		const char* ReadStringTEXTUREchar = ReadStringTEXTURE.c_str();
		Texture2D TempTexture = LoadTexture(ReadStringTEXTUREchar);
		Textures.push_back(TempTexture);
	}
	TextureFile.close();

	auto entity_descriptions = LoadFileText(EntityDescriptionFilePath);

	ParsEntityDescriptions(entity_descriptions);
	

	/*
		Code created by Gustaf
		//
		Because we decided to use symbols to represents entities instead of integers, the level loader had to be changed up. I learned I could use a foreach to iterate through the characters in a string.
		I chose to make use of this iteration by implementing a switch-case because I can make use of the behaviour when each character is checked to massively improve flexibility and ease-of-use when creating new levels. Each character in the string will move the x-value up, and each new line '\n' would increment the y-value, giving a new entity its x and y position. Then to give the entity it's properties I can iterate throught he vector of entity descriptions to assign what kind of entity it is into the level.EntitiesLayer# vector. 
	*/
	//Load Levels
	std::string level_creation = LoadFileText(LevelDirectory);
	Level tLevel;
	int x = 0, y = 0;
	for (char& c : level_creation)
	{
		Entity tEntity;
		switch (c)
		{
			case 'p':
		{
			tEntity.position = Vector2i(x, y);
			for (auto& d : Resources::entitiesdesc)
			{
				if (d.symbolInLevelFile == 'p')
				{
					tEntity.entityDescription = &d;
				}
			}
			//This sets the default player position !!NO MORE THAN 1 PLAYER!!
			tLevel.PlayerPosition.x = x;
			tLevel.PlayerPosition.y = y;
			tLevel.EntetiesLayer1.push_back(tEntity);
			x++;
			break;
		}
		case '#':
		{
			tEntity.position = Vector2i(x, y);
			for (auto& d : Resources::entitiesdesc)
			{
				if (d.symbolInLevelFile == '#')
				{
					tEntity.entityDescription = &d;
				}
			}
			tLevel.EntetiesLayer1.push_back(tEntity);
			x++;
			break;
		}
		case 'b':
		{
			tEntity.position = Vector2i(x, y);
			for (auto& d : Resources::entitiesdesc)
			{
				if (d.symbolInLevelFile == 'b')
				{
					tEntity.entityDescription = &d;
				}
			}
			tLevel.EntetiesLayer1.push_back(tEntity);
			x++;
			break;
		}
		case 's':
		{
			tEntity.position = Vector2i(x, y);
			for (auto& d : Resources::entitiesdesc)
			{
				if (d.symbolInLevelFile == 's')
				{
					tEntity.entityDescription = &d;
				}
			}
			tLevel.EntetiesLayer0.push_back(tEntity);
			x++;
			break;
		}
		case '\n':
		{
			x = 0;
			y++;
			break;
		}
		case '*':
		{
			Levels.push_back(tLevel); //Pushes the new temporary level into the vector of levels.
			tLevel = Level{};
			x = 0; y = -1; //I set y to -1 because otherwise it looks visually "weird" when you have to create a new level on the same line as the asterix in the 'Levels.txt' file where everything is offset by 1 character.
			break;
		}
		default:
			x++;
			break;
		}
	}
}


void Resources::UnloadResources()
{
	for (int i = 0; i < Textures.size(); i++)
	{
		UnloadTexture(Textures[i]);
	}

	for (int i = 0; i < Sounds.size(); i++)
	{
		StopSoundMulti();
		UnloadSound(Sounds[i]);
	}
}