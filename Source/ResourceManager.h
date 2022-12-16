#pragma once
#include "Level.h"

#include "raylib.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>


struct Resources {
	static std::vector<Level> Levels;
	static std::vector<Texture2D> Textures;                       // These vectors was created So I can keep the path of the resources files and access them in level.cpp according to the needs. The entitydescription vector was created to store  the description So i can access it when i load the level by pushing it in there                                                          
	static std::vector<Sound> Sounds;                             // Jonathan & Adarsh
	static std::vector<EntityDescription> entitiesdesc;


	static void LoadResources();                                // Load resources function we made So we can load everything for level in that one function which executes in ResourcreManager.cpp and We Unload the resources at the end of using the function So We do not leak any memory.
	static void UnloadResources();                              // Jonathan
	                                                            
	};


