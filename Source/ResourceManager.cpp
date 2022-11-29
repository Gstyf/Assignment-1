#include "ResourceManager.h"

std::vector<Level> Resources::Levels;
std::vector<Texture2D> Resources::Textures;

std::filesystem::path TextureDirectory = "./Resources/Textures";
std::string LevelDirectory = "./Resources/Levels.txt";

int GetMultiDecimalIntFromString(int& Iterator, std::string String)
	{
	std::string StringToConvert;
	while (isdigit(String.at(Iterator)))
		{
		StringToConvert += String[Iterator];
		Iterator++;
		}

	return (stoi(StringToConvert));
	}


Level ConstructLevelFromString(std::string String)
	{
	int i = 0;
	int Count = 0;
	Entity TempEntity;
	Level TempLevel;

	while (String[i] != '\n')
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
					TempEntity.position.x = GetMultiDecimalIntFromString(i, String);
					Count = 0;
					TempLevel.entities.push_back(TempEntity);
					TempEntity = Entity {};
					break;
					}
				}
			}
		
		i++;
		}

	return(TempLevel);
	}


void Resources::LoadResources()
	{
	//Load Textures
	for (auto const& dir_entry : std::filesystem::directory_iterator{ TextureDirectory })
		{
		const char* LoadTextureDir = dir_entry.path().string().c_str();
		Textures.push_back(LoadTexture(LoadTextureDir));
		}

	//Load Levels
	std::string ReadString;
	std::ifstream LevelFile {LevelDirectory};
	
	while (std::getline(LevelFile, ReadString))
		{
		Levels.push_back(ConstructLevelFromString(ReadString));
		}
	}