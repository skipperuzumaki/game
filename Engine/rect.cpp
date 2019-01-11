#include "rect.h"

rect::rect(pos start, pos end)
{
	y1 = start.y;
	x2 = start.x;
	y2 = end.y;
	x3 = end.x;
	y3 = start.y;
	x4 = end.x;
	y4 = end.y;
	x1 = start.x;
}

rect::rect(pos start, int wdith, int height)
{
	pos end = { start.x + wdith,start.y = height };
	rect(start, end);
}

bool rect::inside(pos p)
{
	if (x1<p.x && x4>p.x && y1<p.y && y4>p.y) {
		return true;
	}
	else {
		return false;
	}
}

bool rect::contains(rect r)
{
	if (r.inside({ x1,x2 }) && r.inside({ x2,y2 }) && r.inside({ x3,y3 }) && r.inside({ x4,y4 })) {
		return true;
	}
	else {
		return false;
	}
}

bool rect::liesin(rect r)
{
	if (inside({ r.x1,r.x2 }) && inside({ r.x2,r.y2 }) &&
		inside({ r.x3,r.y3 }) && inside({ r.x4,r.y4 })) {
		return true;
	}
	else {
		return false;
	}
}
