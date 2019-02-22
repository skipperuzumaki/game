#pragma once
#include "Colors.h"
#include <string>

class sprite
{
public:
	sprite(const std::string filename);
	sprite(int width, int height);
	sprite(const sprite&rhs);
	~sprite();
	sprite& operator=(const sprite&rhs);
	void load(int x, int y, Color c);
	Color fetch(int x, int y) const;
	int getwidth();
	int getheight();
	sprite fliphorizontal() const;
private:
	int width;
	int height;
	Color *start = nullptr;
};

