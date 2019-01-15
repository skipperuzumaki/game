#pragma once
#include <string>
#include "rect.h"
#include "Graphics.h"

class background
{
public:
	background() = default;
	std::string imagelocation;
	int height;
	int width;
	pos loc;
	rect extent;
	void const draw(Graphics &gfx);
	bool const safe(int const srcwth,int const scrht);
};

