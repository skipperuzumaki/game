#pragma once
#include "pos.h"
#include "rect.h"
#include "Graphics.h"
#include <string>
#include "sprite.h"

class avatar
{
public:
	pos pos = pos::pos(-1, -1);
	int width;
	int height;
	rect extent;
	std::string spritelocation;
	sprite sprite = sprite::sprite(0, 0);
};

