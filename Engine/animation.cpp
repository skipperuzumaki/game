#include "animation.h"
#include "ChiliWin.h"
#include <fstream>
#include <cassert>
#include <math.h>


animation::animation(const animation & rhs)
{
	frames.clear();
	current = 0;
	for (int i = 0; i < rhs.size(); i++) {
		frames.push_back(rhs.frameat(i));
	}
}

animation::animation(const std::string filename, int framewidth, int frameheight)
{
	frames.clear();
	current = 0;
	std::ifstream file(filename, std::ios::binary);
	BITMAPFILEHEADER bmhead;
	file.read(reinterpret_cast<char*>(&bmhead), sizeof(bmhead));
	BITMAPINFOHEADER bminfo;
	file.read(reinterpret_cast<char*>(&bminfo), sizeof(bminfo));
	assert(bminfo.biBitCount == 24);
	assert(bminfo.biCompression == BI_RGB);
	int rows = std::abs(bminfo.biWidth / framewidth);
	int columns = std::abs(bminfo.biHeight / frameheight);
	sprite temp1 = sprite(filename);
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			sprite temp = sprite(framewidth, frameheight);
			for (int x = 0; x < framewidth; x++) {
				for (int y = 0; y < frameheight; y++) {
					temp.load(x, y, temp1.fetch((framewidth*r) + x, (frameheight*c) + y));
				}
			}
			frames.push_back(temp);
		}
	}
}

animation::animation()
{
	frames.clear();
	current = 0;
}

sprite animation::getframe()
{
	assert(current < frames.size());
	sprite retval = frames.at(current);
	curdly++;
	if (curdly >= delay) {
		current++;
		curdly = 0;
	}
	if (current >= frames.size()) {
		current = 0;
	}
	return retval;
}

sprite animation::frameat(int i) const
{
	assert(i < frames.size());
	return frames.at(i);
}

void animation::reset()
{
	current = 0;
	curdly = 0;
}

void animation::loadframe(sprite sp)
{
	frames.push_back(sp);
}

void animation::extendanimation(animation an)
{
	for (int i = 0; i < an.size(); i++) {
		frames.push_back(an.frameat(i));
	}
}

int animation::size() const
{
	return int(frames.size());
}

int animation::getcurrent() const
{
	return current;
}

void animation::setdelay(int i)
{
	curdly = 0;
	delay = i;
}


animation::~animation()
{
}
