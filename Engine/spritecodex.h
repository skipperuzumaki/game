#pragma once
#include "sprite.h"

sprite mkpolice() {
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

sprite mkchr() {
	sprite sprite = sprite::sprite(64, 64);
	for (int y = 0; y < sprite.getheight(); y++) {
		for (int x = 0; x < sprite.getwidth(); x++) {
			sprite.load(x, y, Color(
				(x - 215)*(x - 25) + (y - 2)*(y - 2),
				(x - 215)*(x - 25) + (y + 2)*(y + 2),
				(x + 215)*(x + 25) + (y - 2)*(y - 2)));
		}
	}
	return sprite;
}

namespace sprites
{
	sprite police = mkpolice();
	sprite charecter = mkchr();
	sprite gameover = sprite(1024, 576);
}