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
	rect(pos start, pos end);
	rect(pos start, int wdith, int height);
	bool inside(pos p);
	bool contains(rect r);//this parameter rect contain the class rect
	bool liesin(rect r);//this paraneter rect liesin the class rect
};

