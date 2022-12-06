#include "Game.h"
#include "Level.h"

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
	GameManager GMMain = { 896, 512, GameState { GameScreen::TITLE, 0 } };
	
	InitWindow(GMMain.WindowWidth, GMMain.WindowHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);
	
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