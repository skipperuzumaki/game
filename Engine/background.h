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
	std::vector<environment> sectors;
	std::vector<std::vector<direction>> openings;
	void generateroute();
	bool oncrit(int n);
	void generatecontent();
	void cleanlevel();
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

