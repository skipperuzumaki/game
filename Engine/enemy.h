#pragma once
#include "rect.h"
#include "line.h"
#include "sprite.h"
#include "direction.h"

class enemy
{
public:
	pos loc;
	direction facing;
	line sight;
	line die;
	line base;
	rect extent;
	bool dead = false;
	void update();
	bool needtoturn();
};

