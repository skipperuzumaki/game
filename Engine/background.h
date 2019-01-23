#pragma once
#include <string>
#include "rect.h"
#include "Graphics.h"
#include "sprite.h"
#include "enivronment.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "avatar.h"
#include "line.h"

class background
{
public:
	background();
	std::vector<environment> sectors;
	std::vector<std::vector<direction>> openings;
	std::vector<line> surface;
	std::vector<line> ledge;
	bool ignoregravity(avatar &charecter);
	void generateroute();
	bool oncrit(int n);
	void generatecontent();
	void cleanlevel();
	void generateenvironments();
	int start;
	int end;
	int height = 0;
	int width = 0;
	pos loc = pos::pos(-1, -1);
	rect extent;
	sprite level = sprite(height, width);
	bool safe(int const srcwth,int const scrht);
	void constructlevelsprite();
	//add sector dimensions
};

