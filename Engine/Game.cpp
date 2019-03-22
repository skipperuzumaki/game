/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Keyboard.h"
#include <string>
#include <vector>
#include <chrono>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	background bkgr;
	avatar charecter;
	level = world(charecter, bkgr);
}


void Game::Go()
{
	std::chrono::system_clock::time_point bgn = std::chrono::system_clock::now();
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	std::chrono::system_clock::time_point nd = std::chrono::system_clock::now();
	std::chrono::duration<float> dt = nd - bgn;
	frameduration = dt.count();
}

void Game::UpdateModel()
{
	if (started) {
		level.update(wnd.kbd, gfx, frameduration);
		if (level.charecter.dead) {
			disp_points = level.charecter.points;
			level.charecter.points = 0;
			level.reconfigure();
			started = false;
		}
		if (level.charecter.won) {
			started = false;
			level.charecter.won = false;
			winstate = true;
		}
	}
	else if (!winstate) {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			started = true;
			//TODO add loading screen
		}
		else if (wnd.kbd.KeyIsPressed(unsigned('C'))) {
			cred = true;
		}
		else {
			cred = false;
		}
	}
	else {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			started = true;
			winstate = false;
			level.reconfigure();
		}
	}
}

void Game::load()
{
}

void Game::save()
{
}

void Game::ComposeFrame()
{
	if (started) {
		level.draw(gfx, screen);
	}
	else if (cred) {
		gfx.drawspritenonchroma(0, 0, credits);
	}
	else if (!winstate) {
		gfx.drawspritenonchroma(0, 0, titlescreen);
	}
	else {
		gfx.drawspritenonchroma(0, 0, winscreen);
	}
}
