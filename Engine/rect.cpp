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

bool rect::touching(line & l)
{
	//assume line || to axes
	if (l.start.x == x1) {
		if ((l.start.y<y1 && l.end.y>y1) || (l.start.y<y3 && l.end.y>y3)) {
			return true;
		}
	}
	else if (l.start.x == x2) {
		if ((l.start.y<y2 && l.end.y>y2) || (l.start.y<y4 && l.end.y>y4)) {
			return true;
		}
	}
	else if (l.start.y == y1) {
		if ((l.start.x<x1 && l.end.x>x1) || (l.start.x<x3 && l.end.x>x3)) {
			return true;
		}
	}
	else if (l.start.y == y2) {
		if ((l.start.x<x2 && l.end.x>x2) || (l.start.x<x4 && l.end.x>x4)) {
			return true;
		}
	}
	else {
		return false;
	}
	return false;
}

bool rect::crossing(line & l)
{
	if (l.start.x == l.start.y) {
		if (x1 < l.start.x && l.start.x < x2) {
			return true;
		}
	}
	else if (l.start.y == l.end.y) {
		if (y1 < l.start.y && l.start.y < y2) {
			return true;
		}
	}
	return false;
}

int rect::area()
{
	return ((x4 - x1)*(y4 - y1));//TODO abs
}

void rect::offsetx(int x)
{
	x1 += x;
	x2 += x;
	x3 += x;
	x4 += x;

}

void rect::offsety(int y)
{
	y1 += y;
	y2 += y;
	y3 += y;
	y4 += y;
}

rect rect::cross(rect &r)
{//should be fine
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
			return rect(pos(x1, r.y1), pos(r.x4, r.y4));
		}
		else if (inside(pos(r.x2, r.y2)) && inside(pos(r.x4, r.y4))) {
			return rect(pos(r.x1, y1), pos(r.x4, r.y4));
		}
		else if (r.inside(pos(x1, y1)) && r.inside(pos(x2, y2))) {
			return rect(pos(x1, y1), pos(r.x3, y2));
		}
		else if (r.inside(pos(x1, y1)) && r.inside(pos(x3, y3))) {
			return rect(pos(x1, y1), pos(x3, r.y4));
		}
		else if (r.inside(pos(x3, y3)) && r.inside(pos(x4, y4))) {
			return rect(pos(x3, r.y1), pos(x4, y4));
		}
		else if (r.inside(pos(x2, y2)) && r.inside(pos(x4, y4))) {
			return rect(pos(r.x1, y2), pos(x4, y4));
		}
		else {
			if (inside(pos(r.x1, r.y1))) {
				return rect(pos(r.x1, r.y1), pos(x4, y4));
			}
			else if (inside(pos(r.x2, r.y2))) {
				return rect(pos(x1, r.y2), pos(r.x2, y3));
			}
			else if (inside(pos(r.x3, r.y3))) {
				return rect(pos(r.x3, y1), pos(x2, r.y3));
			}
			else if (inside(pos(r.x4, r.y4))) {
				return rect(pos(x1, y1), pos(r.x4, r.y4));
			}
		}
	}
	return rect(pos(-1, -1), pos(-1, -1));
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
	if (inside( pos( r.x1,r.y1 )) && inside( pos( r.x4,r.y4 ))) {
		return true;
	}
	else {
		return false;
	}
}
