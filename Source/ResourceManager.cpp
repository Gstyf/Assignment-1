#include "ResourceManager.h"

std::vector<Level> Resources::Levels;
std::vector<Texture2D> Resources::Textures;

std::string TextureDirectory = "./Resources/Textures/Textures.txt";
std::string LevelDirectory = "./Resources/Levels.txt";


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
	int i = 0;
	int Count = 0;
	Entity TempEntity;
	Level TempLevel;

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


void Resources::LoadResources()
	{
	//Load Textures
	std::string ReadStringTEXTURE;
	std::ifstream TextureFile {TextureDirectory};

	while (std::getline(TextureFile, ReadStringTEXTURE))
		{
		const char* ReadStringTEXTUREchar = ReadStringTEXTURE.c_str();
		Texture2D TempTexture = LoadTexture(ReadStringTEXTUREchar);
		Textures.push_back(TempTexture);
		}
	TextureFile.close();


	//Load Levels
	std::string ReadStringLEVEL;
	std::ifstream LevelFile {LevelDirectory};
	
	while (std::getline(LevelFile, ReadStringLEVEL))
		{
		Levels.push_back(ConstructLevelFromString(ReadStringLEVEL));
		}
	LevelFile.close();
	}