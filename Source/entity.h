#pragma once
#include "myMath.h"

struct EntityDescription
{
	// the properties of the entities
	int Textures = {};
	char symbolInLevelFile = 0;  
	bool IsPlayer = false;                 // This is descrition to all common properties of objects in game. I created it So it is easier to load objects in level without having a hard code for objects. Also it makes it easier to add other objects later on in the game
	                                       // Adarsh Kumar
	bool IsMovable = false;                
	bool IsSwitch = false; 
	bool IsBox = false;
};

class Entity
	{
public:
	Vector2i position;                           // The entity class we created So we can keep the properties which is not common for the objects like (their positions). And I put pointer to entityDescription in entity to assign them the description according to my text file.
	EntityDescription* entityDescription;        // Gustaf
	                                             
	};

