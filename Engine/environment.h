#pragma once
#include <vector>
#include "sprite.h"
#include "rect.h"
#include "direction.h"
#include "line.h"
#include "enemy.h"

class environment
{
public:
	sprite background = sprite(1024, 576);
	std::vector<enemy> police;
	std::vector<line> itemspawn;
	std::vector<line> killzone;
	std::vector<line> surface;
	std::vector<line> ledge;
	environment() = default;
};
