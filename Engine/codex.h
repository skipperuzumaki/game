#pragma once
#include "environment.h"

class codex
{
public:
	environment N[3];
	environment S[3];
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
	enemy police;
	police.loc = pos(64, 448);
	police.base = line(pos(64, 512), pos(500, 512));
	police.facing = direction::west;
	temp.surface.push_back({ pos(64,64),pos(960,64) });
	temp.surface.push_back({ pos(64,512),pos(960,512) });
	temp.ledge.push_back({ pos(64,64),pos(64,512) });
	temp.killzone.push_back({ pos(64,64),pos(64,128) });
	temp.interactibles.push_back({ pos(128,64),pos(128,400) });
	temp.police.push_back(police);
	E[0] = temp;
	E[1] = temp;
	E[2] = temp;
	W[0] = temp;
	W[1] = temp;
	W[2] = temp;
	N[0] = temp;
	N[1] = temp;
	N[2] = temp;
	S[0] = temp;
	S[1] = temp;
	S[2] = temp;

	EW[1] = temp;
	EW[2] = temp;
	EW[3] = temp;
	EW[4] = temp;
	EW[0] = temp;

	NE[1] = temp;
	NE[2] = temp;
	NE[3] = temp;
	NE[4] = temp;
	NE[0] = temp;

	NW[1] = temp;
	NW[2] = temp;
	NW[0] = temp;
	NW[3] = temp;
	NW[4] = temp;

	NEW[1] = temp;
	NEW[2] = temp;
	NEW[0] = temp;
	NEW[3] = temp;
	NEW[4] = temp;

	SEW[1] = temp;
	SEW[2] = temp;
	SEW[0] = temp;
	SEW[3] = temp;
	SEW[4] = temp;

	SE[1] = temp;
	SE[2] = temp;
	SE[3] = temp;
	SE[4] = temp;
	SE[0] = temp;

	SW[1] = temp;
	SW[2] = temp;
	SW[3] = temp;
	SW[4] = temp;
	SW[0] = temp;

	NSE[1] = temp;
	NSE[2] = temp;
	NSE[3] = temp;
	NSE[4] = temp;
	NSE[0] = temp;

	NSW[1] = temp;
	NSW[2] = temp;
	NSW[3] = temp;
	NSW[4] = temp;
	NSW[0] = temp;

	NSEW[1] = temp;
	NSEW[2] = temp;
	NSEW[3] = temp;
	NSEW[4] = temp;
	NSEW[0] = temp;
	NSEW[5] = temp;
	NSEW[6] = temp;
	NSEW[7] = temp;
	NSEW[8] = temp;
	NSEW[9] = temp;
}