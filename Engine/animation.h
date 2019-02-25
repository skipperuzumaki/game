#pragma once
#include "sprite.h"
#include <vector>
#include <string>

class animation
{
public:
	animation(const animation&rhs);
	animation(const std::string filename, int framewidth, int farmeheight);
	animation();
	sprite getframe();
	sprite frameat(int i) const;
	void reset();
	void loadframe(sprite sp);
	void extendanimation(animation an);
	int size() const;
	int getcurrent() const;
	void setdelay(int i);
	~animation();
private:
	std::vector<sprite> frames;
	int current;
	int delay = 5;
	int curdly = 0;
};

