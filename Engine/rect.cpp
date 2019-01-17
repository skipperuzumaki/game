#include "rect.h"

rect::rect(pos start, pos end)
{
	x1 = start.x;
	y1 = start.y;
	x2 = start.x;
	y2 = end.y;
	x3 = end.x;
	y3 = start.y;
	x4 = end.x;
	y4 = end.y;
}

rect::rect(pos start, int width, int height)
{
	pos end = { start.x + width,start.y = height };
	rect(start, end);
}

rect::rect(int x1, int y1, int x4, int y4)
{
	pos p1 = { x1,y1 };
	pos p2 = { x4,y4 };
	rect(p1, p2);
}

bool const rect::inside(pos const &p)
{
	if (x1<p.x && x4>p.x && y1<p.y && y4>p.y) {
		return true;
	}
	else {
		return false;
	}
}

rect rect::cross(rect r)
{
	if (liesin(r)) {
		return rect(x1, y1, x4, y4);
	}
	else if (contains(r)) {
		return r;
	}
	else if (inside({ r.x1,r.y1 })) {
		return rect(r.x1, r.y1, x4, y4);
	}
	else if (inside({ r.x4,r.y4 })) {
		return rect(x1, y1, r.x4, r.y4);
	}
	else {
		return rect(0, 0, 0, 0);
	}
}

bool const rect::liesin(rect &r)
{
	if (r.inside({ x1,x2 }) && r.inside({ x4,y4 })) {
		return true;
	}
	else {
		return false;
	}
}

bool const rect::contains(rect const &r)
{
	if (inside({ r.x1,r.x2 }) && inside({ r.x4,r.y4 })) {
		return true;
	}
	else {
		return false;
	}
}
