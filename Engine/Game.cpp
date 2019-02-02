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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	//TODO make all this automatic
	enemy police;
	enemy police2;
	background bkgr;
	avatar charecter;
	bkgr.surface.push_back({ pos(100,500),pos(700,500) });
	bkgr.surface.push_back({ pos(300,400),pos(800,400) });
	bkgr.surface.push_back({ pos(300,20),pos(800,20) });
	bkgr.ledge.push_back({ pos(200,0),pos(200,1024) });
	bkgr.killzone.push_back({ pos(600,350),pos(600,1024) });
	police.loc = pos(250, 436);
	police.facing = direction::east;
	police.base = { pos(100,500),pos(700,500) };
	police2.loc = pos(350, 336);
	police2.facing = direction::west;
	police2.base = { pos(100,400),pos(700,400) };
	std::vector<enemy> p;
	p.push_back(police);
	p.push_back(police2);
	level = world(charecter, p, bkgr);
}


void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	level.update(vx, vy, upmtm, wnd.kbd, gfx);
	level.kill();
}

void Game::load()
{
}

void Game::save()
{
}

void Game::ComposeFrame()
{
	rect screen = rect(pos(0, 0), pos(gfx.ScreenWidth, gfx.ScreenHeight));
	level.draw(gfx, screen);
}
