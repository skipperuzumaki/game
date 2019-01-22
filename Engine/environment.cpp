#include "environment.h"

bool environment::hasopening(direction d)
{
	for (int i = 0; i < openings.size(); i++) {
		if (openings.at(1) == d) {
			return true;
		}
	}
	return false;
}
