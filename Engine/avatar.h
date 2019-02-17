#pragma once
#include "pos.h"
#include "rect.h"
#include "Graphics.h"
#include <string>
#include "sprite.h"

class avatar
{
public:
	pos pos = pos::pos(480, 256);
	int points = 0;
	rect extent;
	bool dead = false;
	bool won = false;
};