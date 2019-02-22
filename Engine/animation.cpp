#include "animation.h"
#include "ChiliWin.h"
#include <fstream>
#include <cassert>


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
	int rows = bminfo.biWidth / framewidth;
	int columns = bminfo.biHeight / frameheight;
	const int padding = (4 - (bminfo.biWidth * 3) % 4) % 4;
	file.seekg(bmhead.bfOffBits);
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < columns; y++) {
			sprite temp = sprite(framewidth, frameheight);
			for (int y = frameheight - 1; y >= 0; y--) {
				for (int x = 0; x < framewidth; x++) {
					temp.load(x, y, Color(file.get(), file.get(), file.get()));
				}
				file.seekg(padding, std::ios::cur);
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
	return frames.size();
}

void animation::setdelay(int i)
{
	curdly = 0;
	delay = i;
}


animation::~animation()
{
}
