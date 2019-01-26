#pragma once
#include <vector>
#include "sprite.h"
#include "rect.h"
#include "direction.h"
#include "line.h"

class environment
{
public:
	int id;
	sprite background = sprite(0, 0);//TODO change initialiser appropriately
	std::vector<direction> openings;
	std::vector<line> enemyspawn;
	std::vector<line> itemspawn;
	std::vector<line> interactiblespawn;
	std::vector<line> surface;
	std::vector<line> ledge;
	bool hasopening(direction d)
	{
		for (int i = 0; i < openings.size(); i++) {
			if (openings.at(i) == d) {
				return true;
			}
		}
		return false;
	}
};
