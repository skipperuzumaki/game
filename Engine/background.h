#pragma once
#include <string>
#include "rect.h"
#include "Graphics.h"
#include "sprite.h"

class background
{
public:
	std::string spritelocation;
	int height;
	int width;
	pos loc;
	rect extent;
	sprite sprite;
	bool safe(int const srcwth,int const scrht);
};

