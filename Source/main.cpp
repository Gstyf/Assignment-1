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

#include <vector>
#include "myMath.h"

#include "entity.h"

#include "raylib.h"
#include "raymath.h"



struct Level {
	Vector2i PlayerPos;
	std::vector<Vector2i> Walls;
	std::vector<Vector2i> Boxes;
	std::vector<Vector2i> WinPoints;
	};


Vector2i CreateMovementVector()
	{
	int XMVM = IsKeyPressed(KEY_LEFT) - IsKeyPressed(KEY_RIGHT);
	int YMVM = IsKeyPressed(KEY_UP) - IsKeyPressed(KEY_DOWN);
	return Vector2i{ XMVM, YMVM };
	}


bool OccupiedByBox(Vector2i Position, std::vector<Vector2i>* BoxVector)
	{
	for (int i = 0; i < (*BoxVector).size(); i++)
		{
		//if ((*BoxVector)[i] == Position) { return (true); }
		}
	return (false);
	}


bool OccupiedByWall(Vector2i Position, std::vector<Vector2i>* WallVector)
	{
	for (int i = 0; i < (*WallVector).size(); i++)
	{
		//if ((*WallVector)[i] == Position) { return (true); }
	}
	return (false);
	}


Vector2i* GetBox(Vector2i Position, std::vector<Vector2i>* BoxVector)
	{
		for (int i = 0; i < (*BoxVector).size(); i++)
		{
		//if ((*BoxVector)[i] == Position) { return (&(*BoxVector)[i]); }
		}
	return (nullptr);
	}


void MovePlayer(Vector2i MovementVector, Level* MainLevel) //Implement bool return
	{
		//Vector2 FutureMovement = MainLevel->PlayerPos + MovementVector;
		Vector2i FutureMovement = MainLevel->PlayerPos + MovementVector;
		/*if (OccupiedByBox(FutureMovement, &MainLevel->Boxes))
		{
			Vector2i FutureBoxMovement = FutureMovement + MovementVector;
			if (OccupiedByWall(FutureBoxMovement, &MainLevel->Boxes) == false)
			{
				Vector2i* BoxToMove = GetBox(FutureBoxMovement, &MainLevel->Boxes);
				BoxToMove->x = FutureBoxMovement.x;
				BoxToMove->y = FutureBoxMovement.y;
				MainLevel->PlayerPos = FutureMovement;
			}
		}
		else if (OccupiedByWall(FutureMovement, &MainLevel->Walls) == false)
		{
			MainLevel->PlayerPos = FutureMovement;
		}*/
		MainLevel->PlayerPos = FutureMovement;
	}



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
	//Level level;

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
			
			BeginDrawing();

			ClearBackground(BLACK);

			/*DrawRectangle(0, 0, 40, 40, SKYBLUE);
			DrawRectangle(40, 0, 40, 40, DARKGREEN);
			DrawRectangle(40, 40, 40, 40, SKYBLUE);
			DrawRectangle(0, 40, 40, 40, DARKGREEN);*/
			//DrawCircle(player.posOffset.x, player.posOffset.y, player.rsize, RAYWHITE);


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