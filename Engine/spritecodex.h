#pragma once
#include "sprite.h"

namespace police
{
	sprite police() {
		sprite police = sprite(64, 64);
		for (int y = 0; y < police.getheight(); y++) {
			for (int x = 0; x < police.getwidth(); x++) {
				police.load(x, y, Color(
					x,
					y,
					(x + 215)*(x + 25) + (y - 2)*(y - 2)));
			}
		}
		return police;
	}
}