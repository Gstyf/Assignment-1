#include "Game.h"
#include "Level.h"
#include "CONSTANTS.h"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"
#include <iostream>

/*  TODO
CLEANUP & SOUND
UNLOADING OF RESOURCES

*/


int main(void)
	{
	// Initialization
	GameManager GMMain = { GameState { GameScreen::TITLE, 0 } };
	
	InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "raylib [core] example - basic window");
	SetTargetFPS(60);
	InitAudioDevice();
	
	Resources::LoadResources();

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