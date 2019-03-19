#pragma once
#include <vector>
#include "sprite.h"
#include "rect.h"
#include "direction.h"
#include "line.h"
#include "enemy.h"
#include <string>
#include <cassert>

class environment
{
public:
	sprite background = sprite(1024, 576);
	std::vector<enemy> police;
	std::vector<line> interactibles;
	std::vector<line> killzone;
	std::vector<line> surface;
	std::vector<line> ledge;
	void addtile(int x, int y,sprite &s) {
		for (int sx = 0; sx < 64; sx++) {
			for (int sy = 0; sy < 64; sy++) {
				background.load(x + sx, y + sy, s.fetch(sx, sy));
			}
		}
	}
	environment() = default;
	~environment() = default;
	void redefine(std::string layout) {
		assert(layout.length() == 144);
		clear();
		for (int x = 0; x < 16; x++) {
			for (int y = 0; y < 9; y++) {
				char k = layout.at((16 * y) + x);
				if (k == char(101)) {//e
					//pass
				}
				else if (k == char(111)) {//o
					ledge.push_back(line(pos((x * 64) + 64, y * 64), pos((x * 64) + 64, (y * 64) + 64)));
					ledge.push_back(line(pos(x * 64, y * 64), pos(x * 64, (y * 64) + 64)));
					surface.push_back(line(pos(x * 64, y * 64), pos((x * 64) + 64, y * 64)));
					surface.push_back(line(pos(x * 64, (y * 64) + 64), pos((x * 64) + 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(122)) {//z
					ledge.push_back(line(pos((x * 64) + 64, y * 64), pos((x * 64) + 64, (y * 64) + 64)));
					surface.push_back(line(pos(x * 64, y * 64), pos((x * 64) + 64, y * 64)));
					surface.push_back(line(pos(x * 64, (y * 64) + 64), pos((x * 64) + 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(120)) {//x
					ledge.push_back(line(pos(x * 64, y * 64), pos(x * 64, (y * 64) + 64)));
					surface.push_back(line(pos(x * 64, y * 64), pos((x * 64) + 64, y * 64)));
					surface.push_back(line(pos(x * 64, (y * 64) + 64), pos((x * 64) + 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(115)) {//s
					ledge.push_back(line(pos(x * 64, y * 64), pos(x * 64, (y * 64) + 64)));
					ledge.push_back(line(pos((x * 64) + 64, y * 64), pos((x * 64) + 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(104)) {//h
					surface.push_back(line(pos(x * 64, y * 64), pos((x * 64) + 64, y * 64)));
					surface.push_back(line(pos(x * 64, (y * 64) + 64), pos((x * 64) + 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(109)) {//m
					surface.push_back(line(pos(x * 64, y * 64), pos((x * 64) + 64, y * 64)));
					ledge.push_back(line(pos(x * 64, y * 64), pos(x * 64, (y * 64) + 64)));
					ledge.push_back(line(pos((x * 64) + 64, y * 64), pos((x * 64) + 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(117)) {//u
					surface.push_back(line(pos(x * 64, (y * 64) + 64), pos((x * 64) + 64, (y * 64) + 64)));
					ledge.push_back(line(pos(x * 64, y * 64), pos(x * 64, (y * 64) + 64)));
					ledge.push_back(line(pos((x * 64) + 64, y * 64), pos((x * 64) + 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(97)) {//a
					surface.push_back(line(pos(x * 64, y * 64), pos((x * 64) + 64, y * 64)));
					ledge.push_back(line(pos(x * 64, y * 64), pos(x * 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(103)) {//g
					surface.push_back(line(pos(x * 64, y * 64), pos((x * 64) + 64, y * 64)));
					ledge.push_back(line(pos((x * 64) + 64, y * 64), pos((x * 64) + 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(100)) {//d
					surface.push_back(line(pos(x * 64, (y * 64) + 64), pos((x * 64) + 64, (y * 64) + 64)));
					ledge.push_back(line(pos(x * 64, y * 64), pos(x * 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(102)) {//f
					surface.push_back(line(pos(x * 64, (y * 64) + 64), pos((x * 64) + 64, (y * 64) + 64)));
					ledge.push_back(line(pos((x * 64) + 64, y * 64), pos((x * 64) + 64, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("full_sq_tile.bmp"));
				}
				else if (k == char(114)) {//r
					killzone.push_back(line(pos((x * 64) + 64, (y * 64) + 2), pos((x * 64) + 64, (y * 64) + 62)));
					addtile(x * 64, y * 64, sprite("spike_right.bmp"));
				}
				else if (k == char(108)) {//l
					killzone.push_back(line(pos(x * 64, (y * 64) + 2), pos(x * 64, (y * 64) + 62)));
					addtile(x * 64, y * 64, sprite("spike_left.bmp"));
				}
				else if (k == char(98)) {//b
					killzone.push_back(line(pos((x * 64) + 2, (y * 64) + 64), pos((x * 64) + 62, (y * 64) + 64)));
					addtile(x * 64, y * 64, sprite("spike_down.bmp"));
				}
				else if (k == char(116)) {//t
					killzone.push_back(line(pos((x * 64) + 2, y * 64), pos((x * 64) + 62, y * 64)));
					addtile(x * 64, y * 64, sprite("spike_top.bmp"));
				}
			}
		}
	}
	void clear() {
		background.solidcolor(Colors::Magenta);
		surface.clear();
		ledge.clear();
		police.clear();
		killzone.clear();
		interactibles.clear();
	}
};

/*
Legend

s = left + right
h = top + bottom
m = left + right + top
u = left + right + bottom
a = left + top
g = right + top
d = left + bottom
f = right + bottom
e = empty space
r = spike right
l = spike left
b = spike bottom
t = spike top
z = top + bottom + right
x = top + bottom + left
o = full sqare

*/