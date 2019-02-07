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
	police.loc = pos(64, 448);
	police.base = line(pos(64, 512), pos(500, 512));
	police.facing = direction::west;
	background bkgr;
	avatar charecter;
	environment temp;
	environment temp2;
	temp.surface.push_back({ pos(64,64),pos(960,64) });
	temp.surface.push_back({ pos(64,512),pos(960,512) });
	temp.ledge.push_back({ pos(64,64),pos(64,512) });
	temp2 = temp;
	temp2.police.push_back(police);
	for (int i = 0; i < 0; i++) {
		bkgr.sectors.push_back(temp2);
	}
	for (int i = 0; i < 25; i++) {
		bkgr.sectors.push_back(temp);
	}
	level = world(charecter, bkgr);
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
	level.update(wnd.kbd, gfx);
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
