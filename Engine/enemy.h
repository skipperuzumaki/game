#pragma once
#include "rect.h"
#include "line.h"
#include "sprite.h"
#include "direction.h"

class enemy
{
public:
	sprite pic = sprite(64, 64);
	pos loc;
	direction facing;
	line sight;
	line die;
	line base;
	rect extent;
	bool dead = false;
	void update();
	bool needtoturn();
	void mksprite() {
		for (int y = 0; y < pic.getheight(); y++) {
			for (int x = 0; x < pic.getwidth(); x++) {
				pic.load(x, y, Color(
					x,
					y,
					(x + 215)*(x + 25) + (y - 2)*(y - 2)));
			}
		}
	}
};

