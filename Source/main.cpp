#include "Game.h"
#include "Level.h"
#include "CONSTANTS.h"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"
#include <iostream>


/*
TODO JH

Bugfix
Unload resources
Entity and Switch seperation and resourcemanager and switch integration
Logic restructuring
Connection overhaul


*/


int main(void)
	{
	// Initialization
	GameManager GMMain = { GameState { GameScreen::TITLE, 0 } };
	
	InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "raylib [core] example - basic window");
	SetTargetFPS(60);
	InitAudioDevice();
	
	Resources::LoadResources();
	//PlaySound(Resources::Sounds[0]);


	//Game Loop (Runs in Game.cpp)
	while (!WindowShouldClose())
		{
		try
			{
			GMMain.UpdateGameLoop();
			}
		catch (int ERRORID)
			{
			std::cout << "ERROR: " << ERRORID;
			}
		}
	

	//UNLOAD RESOURCES

	CloseWindow(); // Close window and OpenGL context
	return 0;
	}