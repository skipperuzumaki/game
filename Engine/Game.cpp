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
	for (int y = 0; y < sp.getheight(); y++) {
		for (int x = 0; x < sp.getwidth(); x++) {
				sp.load(x, y, Color(
					(x - 215)*(x - 25) + (y - 2)*(y - 2),
					(x - 215)*(x - 25) + (y + 2)*(y + 2),
					(x + 215)*(x + 25) + (y - 2)*(y - 2)));
		}
	}
	for (int y = 0; y < sp.getheight(); y++) {
		for (int x = 0; x < sp.getwidth(); x++) {
			ps.load(x, y, Color(
				(x),
				(y),
				(x + 215)*(x + 25) + (y - 2)*(y - 2)));
		}
	}
	//TODO make all this automatic
	charecter.sprite = sp;
	line l = { pos(100,500),pos(700,500) };
	line l2 = { pos(300,400),pos(800,400) };
	line l1 = { pos(200,0),pos(200,11500) };
	line l3 = { pos(600,350),pos(600,11500) };
	bkgr.surface.push_back(l);
	bkgr.surface.push_back(l2);
	bkgr.ledge.push_back(l1);
	bkgr.ledge.push_back(l3);
	charecter.pos.x = 260;
	charecter.pos.y = 30;
	police.loc = pos(250, 400);
	police.facing = direction::east;
	police.base = l;
	police.pic = ps;
	police2.loc = pos(350, 300);
	police2.facing = direction::west;
	police2.base = l;
	police2.pic = ps;
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
	level.update(vx, vy, stnry, upmtm, wnd.kbd, gfx);
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
