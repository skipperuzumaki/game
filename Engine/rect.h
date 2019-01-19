#pragma once
#include "pos.h"

class rect
{
public:
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;
	rect() = default;
	rect(pos start, pos end);
	rect(pos start, int width, int height);
	//rect(int x1, int y1, int x4, int y4);
	bool const inside(pos const &p);
	rect cross(rect &r);
	bool const contains(rect  const &r);//this paraneter rect liesin the class rect
	bool const liesin(rect &r);//this parameter rect contain the class rect
};

