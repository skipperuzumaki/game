#include "background.h"

bool background::safe(int const srcwth, int const scrht)
{
	rect r = { 0,0,srcwth,scrht };
	return extent.contains(r);
}
