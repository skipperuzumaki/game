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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	for (int y = 0; y < sp.getheight(); y++) {
		for (int x = 0; x < sp.getwidth(); x++) {
				sp.load(x, y, Color(
					(x - 25)*(x - 25) + (y - 2)*(y - 2),
					(x - 25)*(x - 25) + (y + 2)*(y + 2),
					(x + 25)*(x + 25) + (y - 2)*(y - 2)));
		}
	}
	charecter.sprite = sp;
	line l = { pos(0,500),pos(1150,500) };
	line l2 = { pos(300,400),pos(1150,400) };
	line l1 = { pos(200,0),pos(200,11500) };
	line l3 = { pos(600,350),pos(600,11500) };
	bkgr.surface.push_back(l);
	bkgr.surface.push_back(l2);
	bkgr.ledge.push_back(l1);
	bkgr.ledge.push_back(l3);
	charecter.pos.x = 232;
	charecter.pos.y = 300;
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
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		vx = 3.0f;
		stnry = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (!upmtm) {
			vy = -6.0f;
			upmtm = true;
			stnry = false;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		vx = -3.0f;
		stnry = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		//interaction button
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
	if (!stnry) {
		if (bkgr.ignoregravity(charecter,int(vx))) {
			vy = 0.0f;
			vx = 0.0f;
			stnry = true;
			upmtm = false;
		}
		else { vy += 0.15; }//seems fine enough
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
	for (int i = 0; i < gfx.ScreenWidth; i++) {
		gfx.PutPixel(i, 500, { 255,255,255 });
	}
	for (int i = 0; i < gfx.ScreenHeight; i++) {
		gfx.PutPixel(200, i, { 255,255,255 });
	}
	for (int i = 300; i < gfx.ScreenWidth; i++) {
		gfx.PutPixel(i, 400, { 255,255,255 });
	}
	for (int i = 350; i < gfx.ScreenHeight; i++) {
		gfx.PutPixel(600, i, { 255,255,255 });
	}
}
