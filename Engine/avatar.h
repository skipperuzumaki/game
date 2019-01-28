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
	//int width = 60;
	//int height = 100;
	rect extent;
	//void updateextent();
	std::string spritelocation;
	sprite sprite = sprite::sprite(0, 0);
	bool dead = false;
};
/*
void avatar::updateextent()
{
	extent = rect(pos, { pos.x + width, pos.y + height });
}
*/