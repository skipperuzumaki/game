#pragma once
#include "pos.h"
#include "rect.h"
#include "Graphics.h"
#include <string>

class avatar
{
public:
	pos pos;
	int width;
	int height;
	rect extent;
	std::string sprite;
	void draw();//work in progress
};

