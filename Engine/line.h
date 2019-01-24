#pragma once
#include "pos.h"

class line
{
public:
	line() = default;
	line(pos st,pos ed) {
		start = st;
		end = ed;
	}
	pos start;
	pos end;
};
