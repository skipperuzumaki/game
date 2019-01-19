#pragma once
#include <string>
#include "rect.h"
#include "Graphics.h"
#include "sprite.h"
#include "enivronment.h"

class background
{
public:
	std::vector<environment> sectors[25];
	std::vector<direction> openings[25];
	int start;
	int end;
	int height = 0;
	int width = 0;
	pos loc;
	rect extent;
	sprite level = sprite(height, width);
	bool safe(int const srcwth,int const scrht);
	void constructlevelsprite();
};

