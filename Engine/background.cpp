#include "background.h"

bool background::safe(int const srcwth, int const scrht)
{
	rect r = rect(pos(0, 0), pos(srcwth, scrht));
	return extent.contains(r);
}
