/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
*   Pass by const ref if not modify else pointer
* 
********************************************************************************************/

#include "Logic.cpp"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"


//Declaring an enum so I can use a switch-case in main for what to render ont he screen.
typedef enum GameScreen { TITLE = 0, GAMEPLAY, GAMEOVER, ENDING } GameScreen;


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

	
int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 440;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	GameScreen currentScreen = TITLE;
	Entity player;
	Level MainLevel{ Vector2i {0,0} };

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		//IMPLEMENTING SWITCH CASE FOR MAIN MENU, GAME AND GAME OVER SCREEN

		switch (currentScreen)
		{
		case TITLE:
			BeginDrawing();

			ClearBackground(BLACK);

			DrawText("Welcome! You are about to play a shitty game by team 7.", 100, 200, 20, RAYWHITE);
			DrawText("Press a key to get to next screen.", 100, 300, 10, RAYWHITE);


			EndDrawing();

			if (IsKeyPressed(KEY_SPACE)) { currentScreen = GAMEPLAY; }
			break;
		case GAMEPLAY:
			
			//Logic
			MovePlayer(CreateMovementVector(), &MainLevel);
			

			//Rendering
			BeginDrawing();

			ClearBackground(BLACK);

			//IMPLEMENT RENDERING HERE::
			DrawCircle(MainLevel.PlayerPos.x * 64, MainLevel.PlayerPos.y*64, 32, RAYWHITE);

			EndDrawing();

			break;
		case GAMEOVER:
			break;
		case ENDING:
			break;

		}

	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}