#pragma once
#include <string>
#include "rect.h"
#include "Graphics.h"

class background
{
public:
	std::string imagelocation;
	int height;
	int width;
	pos loc;
	rect extent;
	void draw(Graphics &gfx) const;
	bool safe(int const srcwth,int const scrht);
};

