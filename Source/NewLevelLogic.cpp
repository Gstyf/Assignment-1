#include "ResourceManager.h"
#include "Level.h"
#include "CONSTANTS.h"

struct GridComponent { //Seperates the grid into two levels, Level 0 being objects that can be moved through
	Entity Level0;
	Entity Level1;
	};


struct EntityGrid { 
private: 
	GridComponent InternalArray[(XTILECOUNT * YTILECOUNT)]; //Create grid of size Xcells * Ycells

public:
	GridComponent GetAtPos(int XIndex, int YIndex)
		{
		return InternalArray[XIndex + YIndex * XTILECOUNT];
		}


	void SetAtPos(int XIndex, int YIndex, GridComponent Value)
		{
		InternalArray[XIndex + YIndex * XTILECOUNT] = Value;
		}


	EntityGrid (std::vector<Entity> Level0Vector, std::vector<Entity> Level1Vector) 
		{
		
		}
	};



void SetGridLevelToVector(int Level, std::vector<Entity> LevelVector, EntityGrid Grid)
	{
	for (int i = 0; i < LevelVector.size(); i++)
		{
		Entity TempEntity = LevelVector[i];
		Grid.SetAtPos(TempEntity.position.x, TempEntity.position.y, TempEntity.entityType);
		}
	}
