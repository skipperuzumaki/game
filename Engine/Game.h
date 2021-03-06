/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "avatar.h"
#include "rect.h"
#include "sprite.h"
#include "background.h"
#include "enemy.h"
#include "world.h"
#include "Sound.h"
#include <chrono>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void load();
	void save();
private:
	MainWindow& wnd;
	Graphics gfx;
	float frameduration = -1.0f;
	std::string savelocation;
	bool started = false;
	bool timeup = false;
	bool pointstate = false;
	bool lvl_tm_init = false;
	bool go_for_it;
	int buff = 0;
	bool cred = false;
	bool tut = false;
	bool ld = false;
	int disp_points = -1;
	world level;
	sprite points = sprite(std::string("pointstate.bmp"));
	sprite loading = sprite(std::string("loadingscreen.bmp"));
	sprite titlescreen = sprite(std::string("titlescreen.bmp"));
	sprite timeupscreen = sprite(std::string("timeup.bmp"));
	sprite credits = sprite(std::string("game_credits.bmp"));
	sprite tutorial = sprite(std::string("castle_bg.bmp"));
	bool ldng = false;
	rect screen = rect(pos(0, 0), pos(gfx.ScreenWidth, gfx.ScreenHeight));
	std::chrono::system_clock::time_point lvl_strt_time;
};