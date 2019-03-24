#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "avatar.h"
#include "rect.h"
#include "sprite.h"
#include "background.h"
#include "enemy.h"
#include <vector>

class world
{
public:
	void draw(Graphics& gfx, rect screen);
	void update(Keyboard& kbd, Graphics& gfx, float dt, bool grav);
	void reconfigure();
	void configure();
	world(avatar & a, background & b);
	avatar charecter;
	background bkgr;
	world() = default;
	float vx = 0.0f, vy = 0.0f;
	bool upmtm = false;
	bool paused = false;
	bool justafterconfig = false;
	int killer = -1;
	int dying = -1;
	direction chfac = direction::west;
	void reset();
	~world();
	rect screen = rect(pos(0, 0), pos(1024, 576));
	sprite exit = sprite(std::string("exit.bmp"));
};

