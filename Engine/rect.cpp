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
	pos end = pos( start.x + width,start.y + height );
	rect(start, end);
}
/*
rect::rect(int x1, int y1, int x4, int y4)
{
	pos p1 = pos( x1,y1 );
	pos p2 = pos( x4,y4 );
	rect(p1, p2);
}
*/
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
		return rect(pos(x1, y1), pos(x4, y4));
	}
	else if (contains(r)) {
		return r;
	}
	else {
		if (inside(pos(r.x1, r.y1)) && inside(pos(r.x2, r.y2))) {
			return rect(pos(r.x1, r.y1), pos(x3, r.y2));
		}
		else if (inside(pos(r.x1, r.y1)) && inside(pos(r.x3, r.y3))) {
			return rect(pos(r.x1, r.y1), pos(r.x3, y4));
		}
		else if (inside(pos(r.x3, r.y3)) && inside(pos(r.x4, r.y4))) {
			return rect(pos(r.x3, y1), pos(r.x4, r.y4));
		}
		else if (inside(pos(r.x2, r.y2)) && inside(pos(r.x4, r.y4))) {
			return rect(pos(x1, r.y2), pos(r.x4, r.y4));
		}
	}
}

bool const rect::liesin(rect &r)
{
	if (r.inside( pos( x1,x2 )) && r.inside( pos( x4,y4 ))) {
		return true;
	}
	else {
		return false;
	}
}

bool const rect::contains(rect const &r)
{
	if (inside( pos( r.x1,r.x2 )) && inside( pos( r.x4,r.y4 ))) {
		return true;
	}
	else {
		return false;
	}
}
