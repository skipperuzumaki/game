#pragma once
#include "rect.h"
#include "line.h"
#include "sprite.h"
#include "direction.h"

class enemy
{
public:
	sprite pic = sprite(0, 0);
	pos loc;
	direction facing;
	pos center;
	line sight;
	line die;
	line base;
	rect extent;
	bool dead = false;
	void update();
	bool needtoturn();
};

