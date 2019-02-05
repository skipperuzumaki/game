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
	rect extent;
	sprite sprite = sprite::sprite(64, 64);
	void mksprite() {
		for (int y = 0; y < sprite.getheight(); y++) {
			for (int x = 0; x < sprite.getwidth(); x++) {
				sprite.load(x, y, Color(
					(x - 215)*(x - 25) + (y - 2)*(y - 2),
					(x - 215)*(x - 25) + (y + 2)*(y + 2),
					(x + 215)*(x + 25) + (y - 2)*(y - 2)));
			}
		}
	}
	bool dead = false;
};