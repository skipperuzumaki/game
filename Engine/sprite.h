#pragma once
#include "Colors.h"

class sprite
{
public:
	sprite(int width, int height);
	sprite(const sprite&rhs);
	~sprite();
	sprite& operator=(const sprite&rhs);
	void load(int x, int y, Color c);
	Color fetch(int x, int y) const;
	int getwidth();
	int getheight();
private:
	int width;
	int height;
	Color *start = nullptr;
};

