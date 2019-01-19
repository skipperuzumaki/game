#pragma once
#include <string>
#include "rect.h"
#include "Graphics.h"
#include "sprite.h"
#include "enivronment.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

class background
{
public:
	background();
	std::vector<environment> sectors[25];
	std::vector<std::vector<direction>> openings[1];
	void generateroute();
	int start;
	int end;
	int height = 0;
	int width = 0;
	pos loc = pos(-1, -1);
	rect extent;
	sprite level = sprite(height, width);
	bool safe(int const srcwth,int const scrht);
	void constructlevelsprite();
};

