#pragma once
#include "environment.h"

class codex
{
public:
	environment E[3];
	environment W[3];
	environment EW[5];
	environment NE[5];
	environment NW[5];
	environment NEW[5];
	environment SEW[5];
	environment SE[5];
	environment SW[5];
	environment NSE[5];
	environment NSW[5];
	environment NSEW[10];
	codex();
};

codex c;

codex::codex()
{
	environment temp;
	//E start;
	temp.surface.push_back({ pos(64,64),pos(960,64) });
	temp.surface.push_back({ pos(64,512),pos(960,512) });
	temp.ledge.push_back({ pos(64,64),pos(64,512) });
	E[0] = temp;
}