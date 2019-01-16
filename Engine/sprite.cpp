#include "sprite.h"
#include "ChiliWin.h"
#include <fstream>
#include <cassert>


sprite::sprite(const std::string filename)
{
	std::ifstream file(filename, std::ios::binary);
	BITMAPFILEHEADER bmhead;
	file.read(reinterpret_cast<char*>(&bmhead), sizeof(bmhead));
	BITMAPINFOHEADER bminfo;
	file.read(reinterpret_cast<char*>(&bminfo), sizeof(bminfo));
	assert(bminfo.biBitCount == 24);
	assert(bminfo.biCompression == BI_RGB);

	width = bminfo.biWidth;
	height = bminfo.biHeight;

	start = new Color[width*height];
	file.seekg(bmhead.bfOffBits);

	const int padding = (4 - (width * 3) % 4) % 4;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			load(x, y, Color(file.get(), file.get(), file.get()));
		}
		file.seekg(padding, std::ios::cur);
	}
}

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
