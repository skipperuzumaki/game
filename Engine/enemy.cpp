#include "enemy.h"

void enemy::update(float dt)
{
	if (facing == east) {
		loc.x += int(90.0f*dt);
	}
	else if (facing == west) {
		loc.x -= int(90.0f*dt);
	}
	pos center = loc + pos(30,5);
	pos siend;
	if (facing == east) {
		siend = pos(center.x + 200, center.y);
		sight = { center,siend };
	}
	else if (facing == west) {
		siend = pos(center.x - 200, center.y);
		sight = { siend,center };
	}
	siend = pos(loc.x + 64, loc.y + 64);
	extent = rect(loc, siend);
	if (facing == east) {
		die = { loc + pos(0,-1),pos(extent.x2 ,extent.y2 - 1) };
	}
	else if (facing == west) {
		die = { pos(extent.x3,extent.y3 + 1),siend + pos(0, 1) };
	}
	if (needtoturn()) {
		if (facing == east) {
			facing = west;
		}
		else if (facing == west) {
			facing = east;
		}
	}
}

bool enemy::needtoturn()
{
	if (facing == east) {
		if (extent.x4 >= base.end.x) {
			return true;
		}
	}
	else if (facing == west) {
		if (extent.x2 <= base.start.x) {
			return true;
		}
	}
	return false;
}
