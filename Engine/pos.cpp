#include "pos.h"

pos pos::operator+(pos const & obj)
{
	return pos({ x + obj.x,y + obj.y });
}

pos::pos(int x1, int y1)
{
	x = x1;
	y = y1;
}

pos pos::operator*(int i)
{
	return pos({ i*x,i*y });
}

bool const pos::operator==(pos const & obj)
{
	if (obj.x == x && obj.y == y) {
		return true;
	}
	else { return false; }
}
