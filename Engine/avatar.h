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
	avatar() = default;
	void draw(Graphics &gfx);//work in progress
};

