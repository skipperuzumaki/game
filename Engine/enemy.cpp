#include "enemy.h"

void enemy::update()
{
	//TODO add motions
	if (needtoturn()) {
		if (facing == east) {
			facing = west;
		}
		else if (facing == west) {
			facing = east;
		}
	}
	loc.x += 2;
	center = loc + pos(30,50);
	pos siend;
	if (facing == east) {
		siend = pos(center.x + 100, center.y);
		sight = { center,siend };
	}
	else if (facing == west) {
		siend = pos(center.x - 100, center.y);
		sight = { siend,center };
	}
	siend = pos(center.x + 60, center.y + 100);
	extent = rect(loc, siend);
	if (facing == east) {
		die = { loc,pos(extent.x2,extent.y2) };
	}
	else if (facing == west) {
		die = { pos(extent.x3,extent.y3),siend };
	}
}

bool enemy::needtoturn()
{
	if (facing == east) {
		if (pos(extent.x4, extent.y4) == base.end) {
			return true;
		}
		else if (extent.x4 > base.end.x) {
			return true;
		}
	}
	else if (facing == west) {
		if (pos(extent.x2, extent.y2) == base.start) {
			return true;
		}
		else if (extent.x2 < base.start.x) {
			return true;
		}
	}
	return false;
}
