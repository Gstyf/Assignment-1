#pragma once
#include "Level.h"

#include "raylib.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>


struct Resources {
	static std::vector<Level> Levels;
	static std::vector<Texture2D> Textures;
	static std::vector<Sound> Sounds;
	static std::vector<EntityDescription> entitiesdesc;

	static void LoadResources();
	
	
	};


