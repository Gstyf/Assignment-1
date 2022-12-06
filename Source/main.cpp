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
Logic restructuring


*/




	
int main(void)
	{
	// Initialization
	GameManager GMMain = { 896, 512, GameState { GameScreen::TITLE, 0 } };
	Resources::LoadResources();
	
	InitWindow(GMMain.WindowWidth, GMMain.WindowHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);
	

	//Game Loop (Runs in Game.cpp)
	try 
		{
		GMMain.UpdateGameLoop();
		}
	catch (int ERRORID)
		{
		std::cout << "ERROR: " << ERRORID;
		}
	

	//UNLOAD RESOURCES

	CloseWindow(); // Close window and OpenGL context
	return 0;
	}