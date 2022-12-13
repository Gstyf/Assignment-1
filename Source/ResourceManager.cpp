#include "ResourceManager.h"


std::vector<Level> Resources::Levels;
std::vector<Texture2D> Resources::Textures;
std::vector<Sound> Resources::Sounds;

std::vector<EntityDescription> Resources::entitiesdesc;


constexpr const char* TextureDirectory = "./Resources/Textures/Textures.txt";
constexpr const char* LevelDirectory = "./Resources/Levels.txt";
constexpr const char* SoundDirectory = "./Resources/Sounds/Sounds.txt";

constexpr const char* EntityDescriptionFilePath = "./Resources/Entities.txt";

int GetMultiDecimalIntFromString(int& Iterator, std::string String)
	{
	std::string StringToConvert;
	while (isdigit(String.at(Iterator)))
		{
		StringToConvert += String[Iterator];
		Iterator++;
		if (Iterator >= String.size()) { break; }
		}
	
	return (stoi(StringToConvert));
	}

Level ConstructLevelFromString(std::string String)
{
	Entity TempEntity;
	Level TempLevel;
	int i = 0, y = 0;
	int Count = 0; // might not need this one

	for (int i = 0; i < String.size();)
		{
		if (isdigit(String.at(i)))
			{
			switch (Count)
				{
				case (0):
					{
					TempEntity.entityType = static_cast<EntityType> (GetMultiDecimalIntFromString(i, String));
					Count++;
					break;
					}

				case (1):
					{
					TempEntity.position.x = GetMultiDecimalIntFromString(i, String);
					Count++;
					break;
					}

				case (2):
					{
					TempEntity.position.y = GetMultiDecimalIntFromString(i, String);
					Count = 0;
					TempLevel.entities.push_back(TempEntity);
					TempEntity = Entity {};
					break;
					}
				}
			}
		else { i++; }
		}
	return(TempLevel);
}

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
									desc.Movable = true;
								}
								else if (accept_string(&cursor, "immovable"))
								{
									desc.Movable = false;
								}
							}
						}
					}


					eat_space(&cursor);
					if (accept_string(&cursor, "texture"))
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
								}
								else if (accept_string(&cursor, "wall"))
								{
									desc.Textures = 1;
								}
								else if (accept_string(&cursor, "box"))
								{
									desc.Textures = 2;
								}
								else if (accept_string(&cursor, "switch"))
								{
									desc.Textures = 3;
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
							desc.inlevelfile = *cursor;
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
	

	//Load Levels
	std::string level_creation = LoadFileText(LevelDirectory);
	Level tLevel;
	Entity tEntity;
	int x = 0, y = 0;
	for (char& c : level_creation)
	{
		switch (c)
		{
		case 'p':
		{
			//Entity tEntity;
			tEntity.position = Vector2i(x, y);
			tEntity.entityType = EntityType::PLAYER;
			tEntity.IsPlayer = true;
			tLevel.entities.push_back(tEntity);
			x++;
			break;
		}
		case '#':
		{
			//Entity tEntity;
			tEntity.position = Vector2i(x, y);
			tEntity.entityType = EntityType::WALL;
			tEntity.IsPlayer = false;
			tLevel.entities.push_back(tEntity);
			x++;
			break;
		}
		break;
		case 'b':
		{
			//Entity tEntity;
			tEntity.position = Vector2i(x, y);
			tEntity.entityType = EntityType::BOX;
			tEntity.IsPlayer = false;
			tLevel.entities.push_back(tEntity);
			x++;
			break;
		}
		break;
		case 's':
		{
			//Entity tEntity;
			tEntity.position = Vector2i(x, y);
			tEntity.entityType = EntityType::SWITCH;
			tEntity.IsPlayer = false;
			tLevel.entities.push_back(tEntity);
			x++;
			break;
		}
		break;
		case '\n':
		{
			x = 0;
			y++;
			break;
		}
		break;
		case '*':
		{
			Levels.push_back(tLevel);
			tLevel.entities.clear();
			x = 0; y = -1;
			break;
		}


		break;
		default:
			x++;
			break;
		}
	}
}


