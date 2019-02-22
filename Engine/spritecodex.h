#pragma once
#include "sprite.h"
#include "animation.h"

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

sprite mkchr1() {
	sprite sprite = sprite::sprite(64, 64);
	for (int y = 0; y < sprite.getheight(); y++) {
		for (int x = 0; x < sprite.getwidth(); x++) {
			sprite.load(x, y, Color(
				(x )*(x) + (y - 2)*(y - 2),0,0));
		}
	}
	return sprite;
}

animation mkchrani() {
	animation c;
	c.loadframe(mkchr());
	c.loadframe(mkchr1());
	return c;
}

namespace sprites
{
	sprite police = mkpolice();
	animation charecter = mkchrani();
	sprite gameover = sprite(1024, 576);
}