#include "sprite.h"


sprite::sprite(int width, int height)
	:
	width(width),
	height(height),
	start(new Color[width*height] )
{
}

sprite::sprite(const sprite &rhs)
	:
	sprite(rhs.width,rhs.height)
{
	const int npixel = width * height;
	for (int i = 0; i < npixel; i++) {
		start[i] = rhs.start[i];
	}
}

sprite::~sprite()
{
	delete[] start;
	start = nullptr;

}

sprite & sprite::operator=(const sprite &rhs)
{
	width = rhs.width;
	height = rhs.height;
	delete[] start;
	start = new Color[width*height];

	const int npixel = width * height;
	for (int i = 0; i < npixel; i++) {
		start[i] = rhs.start[i];
	}

	return *this;
}

void sprite::load(int x, int y, Color c)
{
	start[y*width + x] = c;
}

Color sprite::fetch(int x, int y) const
{
	return start[y*width + x];
}

int sprite::getwidth()
{
	return width;
}

int sprite::getheight()
{
	return height;
}
