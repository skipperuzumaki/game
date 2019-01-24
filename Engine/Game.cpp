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
//make sure motion is at 1 pixel per frame or slower

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	for (int y = 0; y < sp.getheight(); y++) {
		for (int x = 0; x < sp.getwidth(); x++) {
			if (x < 70 && x>50) {
				sp.load(x, y, Colors::Magenta);
			}
			else {
				sp.load(x, y, Color(
					(x - 25)*(x - 25) + (y - 2)*(y - 2),
					(x - 25)*(x - 25) + (y + 2)*(y + 2),
					(x + 25)*(x + 25) + (y - 2)*(y - 2)));
			}
		}
	}
	charecter.sprite = sp;
	line l = { pos(0,500),pos(1150,500) };
	bkgr.surface.push_back(l);
	charecter.pos.x = -13;
	charecter.pos.y = 120;
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
	if (!stnry) {
		if (bkgr.ignoregravity(charecter)) {
			vy = 0.0f;
			vx = 0.0f;
			stnry = true;
		}
		else{ vy += 0.15; }//seems fine enough
	}
	//after updating everything else
	if (bkgr.safe(gfx.ScreenHeight, gfx.ScreenHeight)) {
		bkgr.loc.x -= int(vx);
		bkgr.loc.y -= int(vy);
	}
	else {
		charecter.pos.x += int(vx);
		charecter.pos.y += int(vy);
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
	//bkgr.cleanlevel();
	rect screen = rect(pos(0, 0), pos(gfx.ScreenWidth, gfx.ScreenHeight));
	gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, charecter.sprite);
}
