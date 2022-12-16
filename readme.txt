Group 7:
Members:
Jonathan Hedvall
Adarsh Kumar
Gustaf Styf

Instructions:
Welcome to the Team 7 Sokoban game Suckoban. The goal is to push boxes onto switches. Once all switches have a box on them you win the level. Simple?
Controls: Arrow keys to move, R to reset the level, A to immediately win and skip to next level.
You can create your own levels as well, if you think you're up to it. Inside the Resource folder there is a 'HowToCreateALeve.txt' file with instructions.

Documents:

//CPP
Game.cpp #Logic for game (Includes call to LevelLogic) //Jonathan & gustaf
Graphics.cpp #Used to render the game //Everyone
Main.cpp #Initializes resources & gamestate, runs game, deinitializes resources //Jonathan
LevelLogic.cpp #Handles movement, sound & wincondition //Jonathan
ResourceMananger.cpp #Loads levels, textures, entities & sounds //Everyone


//HEADER
Constants.h #Constants used for the game //Jonathan
Entity.h #Defines entities //Gustaf & Adarsh
Game.h #Defines gamestate and gamestate functions //Jonathan
Level.h #Defines storage for levels, grid system & logic function //Jonathan
myMath.h #Vector2 operators //Fillipo!! (Zombie game) 
ResourceManager.h #Defines storage of resources (Levels, textures, sounds & entitydescriptions) //Jonathan & Adarsh


//FILE SYSTEM
There is a resources folder that contains: 
	Enteties.txt (Used for entitydescription)
	Levels.txt (Used to store levels)
	HowToCreateLevel (Explains how to make level)
	
	Sounds (Folder):
		Sounds.txt (Adresses to sounds to be loaded)
		{Sound files}.wav (Different sound files used in game)
		
	Textures (Folder):
		Textures.txt (Adresses to textues to be loaded)
		{Textures}.png (Different textures used in game)
		
		
Main.cpp creates the gamestate (see game.h), initializes raylib stuff, Loads resources (see ResourceManager.cpp) and starts gameloop, later it unloads resources before closing (see ResourceManager.cpp)

Game.cpp has a UpdateGameLoop function which is called each frame of the gameloop, it handles the logic of the gamestate and then if the game is in gameplay state handles additional logic (see LevelLogic.cpp & Level.h), it then calls RenderGraphics which renders the game (See Graphics.cpp)		


Git Repositiory:
https://github.com/Gstyf/Assignment-1