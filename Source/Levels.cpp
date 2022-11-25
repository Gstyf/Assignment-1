#include "myMath.h"
#include <vector>

struct Level {
	Vector2i PlayerPos;
	std::vector<Vector2i> Walls;
	std::vector<Vector2i> Boxes;
	std::vector<Vector2i> WinPoints;
	};