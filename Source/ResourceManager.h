#pragma once
#include "Level.h"

#include "raylib.h"

#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>


struct Resources {
	static std::vector<Level> Levels;
	static std::vector<Texture2D> Textures;

	static void LoadResources();
	};


