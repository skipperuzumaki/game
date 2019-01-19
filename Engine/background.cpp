#include "background.h"

bool background::safe(int const srcwth, int const scrht)
{
	rect r = rect(pos(0, 0), pos(srcwth, scrht));
	return extent.contains(r);
}

void background::constructlevelsprite()
{
	for (int y = 0; y < level.getheight(); y++) {
		for (int x = 0; x < level.getwidth(); x++) {
			int h = x / sectors->at(1).background.getwidth();
			int k = y / sectors->at(1).background.getheight();
			level.load(x, y, sectors->at(((k * 5) + h)).background.fetch((x - h), (y - k)));
		}
	}
}
