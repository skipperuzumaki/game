#pragma once
#include <string>
#include "rect.h"
#include "Graphics.h"
#include "sprite.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "avatar.h"
#include "line.h"
#include "environment.h"
#include <string>

class background
{
public:
	background();
	std::vector<line> killzone;
	std::vector<environment> sectors;
	std::vector<std::vector<direction>> openings;
	std::vector<line> surface;
	std::vector<line> ledge;
	std::vector<line> interactibles;
	std::vector<line> interactiblesbackup;
	std::vector<enemy> police;
	std::vector<enemy> policebackup;
	line endpoint;
	line epbkup;
	void updatelines();
	bool ignoregravity(avatar &charecter);
	void generateroute();
	bool hasopening(int n, direction d);
	void generatecontent();
	void cleanlevel();
	void generateenvironments();
	void move(int vx, int vy);
	int start;
	int end;
	int height = 2880;
	int width = 5120;
	pos loc = pos::pos(0, 0);
	rect extent;
	sprite level = sprite(height, width);
	bool safe(int const srcwth,int const scrht);
	void constructlevelsprite();
	void polbkup();
	void calcstend();
	//add sector dimensions
};

