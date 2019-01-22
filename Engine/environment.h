#pragma once
#include <vector>
#include "sprite.h"
#include "rect.h"
#include "direction.h"

class environment
{
public:
	int id;
	sprite background = sprite(0, 0);//TODO change initialiser appropriately
	std::vector<direction> openings;
	std::vector<rect> enemyspawn;
	std::vector<rect> itemspawn;
	std::vector<rect> interactiblespawn;
	bool hasopening(direction d);
};
