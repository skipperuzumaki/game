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
#include <iostream>
#include <fstream>
#include <sstream>


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
	if (!lvl_tm_init) {
		lvl_strt_time = bgn;
		lvl_tm_init = true;
	}
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	std::chrono::system_clock::time_point nd = std::chrono::system_clock::now();
	std::chrono::duration<float> dt = nd - bgn;
	std::chrono::duration<float> ldt = nd - lvl_strt_time;
	if (int(ldt.count()) >= 120) {
		timeup = true;
	}
	frameduration = dt.count();
}

void Game::UpdateModel()
{
	if (timeup) {
		disp_points = level.charecter.points;
		level.charecter.points = 0;
		level.reconfigure();
		started = false;
		save();
	}
	if (started) {
		level.update(wnd.kbd, gfx, frameduration);
		if (level.charecter.dead) {
			disp_points = level.charecter.points;
			level.charecter.points = 0;
			level.reconfigure();
			started = false;
			pointstate = true;
			save();
		}
		if (level.charecter.won) {
			level.charecter.won = false;
			started = true;
			level.reconfigure();
		}
	}
	else if (!pointstate) {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			started = true;
			disp_points = -1;
			timeup = false;
			lvl_tm_init = false;
		}
		else if (wnd.kbd.KeyIsPressed(unsigned('C'))) {
			cred = true;
		}
		else if (wnd.kbd.KeyIsPressed(unsigned('L'))) {
			ld = true;
		}
		else {
			cred = false;
			ld = false;
		}
	}
	else if (!started) {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			pointstate = false;
			disp_points = -1;
			timeup = false;
			lvl_tm_init = false;
		}
	}
	else {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			disp_points = -1;
			timeup = false;
			lvl_tm_init = false;
		}
	}
}

void Game::load()
{
	std::ifstream leaderboard;
	leaderboard.open("leaderboard.txt");
	std::string data;
	leaderboard >> data;
	std::istringstream ss(data);
	std::string line;
	int i = 64;
	while (std::getline(ss, line))
	{
		gfx.drawnumber(pos(64,i),std::stoi(line, nullptr, 10));
		i += 64;
	}
	leaderboard.close();
}

void Game::save()
{
	std::fstream leaderboard;
	leaderboard.open("leaderboard.txt");
	std::string data;
	leaderboard >> data;
	std::istringstream ss(data);
	std::string line;
	int q[10];
	while (std::getline(ss, line))
	{
		bool p = true;
		int k = std::stoi(line, nullptr, 10);
		for (int i = 0; i < 5; i++) {
			if (k < disp_points && p) {
				q[i] = disp_points;
				p = false;
			}
			else {
				q[i] = k;
			}
		}
	}
	leaderboard.close();
	leaderboard.open("leaderboard.txt");
	leaderboard.clear();
	for (int i = 0; i < 5; i++) {
		leaderboard << q[i] << std::endl;
	}
}

void Game::ComposeFrame()
{
	if (started) {
		level.draw(gfx, screen);
	}
	else if (cred) {
		gfx.drawspritenonchroma(0, 0, credits);
	}
	else if (ld) {
		load();
	}
	else if (timeup) {
		gfx.drawspritenonchroma(0, 0, timeupscreen);
		if (disp_points != -1) {
			gfx.drawnumber(pos(64, 64), disp_points);
		}
	}
	else if (pointstate) {
		if (disp_points != -1) {
			gfx.drawnumber(pos(64, 64), disp_points);
		}
	}
	else {
		gfx.drawspritenonchroma(0, 0, titlescreen);
	}

}
