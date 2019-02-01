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
	void update(float& vx, float& vy, bool& upmtm, Keyboard& kbd, Graphics& gfx);
	void kill();
	world(avatar & a, std::vector<enemy>& p, background & b);
	avatar charecter;
	std::vector<enemy> police;
	background bkgr;
	world() = default;
	~world();
};

