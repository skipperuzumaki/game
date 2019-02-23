#pragma once

#include "sprite.h"
#include "animation.h"
#include <string>

namespace sprites
{
	animation police = animation(std::string("enemy.bmp"), 64, 64);
	animation policeatk = animation(std::string("enemy_atk.bmp"), 128, 64);
	animation charecter = animation(std::string("charecter.bmp"), 64, 64);
	animation charecteratk = animation(std::string("charecter_atk.bmp"), 64, 64);
	sprite gameover = sprite(1024, 576);
	sprite castle_bg = sprite(std::string("castle_bg.bmp"));
}