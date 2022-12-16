#include "Game.h"
#include "Level.h"
#include "CONSTANTS.h"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"
#include <iostream>

/* Jonathan Hedvall
The reason this gamestate system exists in the manner it does is to allow us to move as much code as possible into their own dedicated sections where we can keep the document to a single purpose and-
-so that a clear chain of executions can be determined. For example a call to the movementlogic looks like this:

Main.cpp (Contains gameloop) -> UpdateGameLoop() -> Game.cpp (Handles gamestate logic) -> CurrentLevel.Update() -> LevelLogic.cpp (Handles level logic)

This way it's easy to add or remove parts from the game and they are not connected except for small openings.
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
	Resources::UnloadResources();
	CloseAudioDevice();

	CloseWindow(); // Close window and OpenGL context
	return 0;
	}