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
	if (charecter.extent.crossing(police.die)) {
		police.dead = true;
	}
	police.update();
	if (charecter.extent.crossing(police2.die)) {
		police2.dead = true;
	}
	police2.update();
	if (charecter.extent.crossing(police.sight)|| charecter.extent.crossing(police2.sight)){
		charecter.dead = true;
	}
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
		if (bkgr.ignoregravity(charecter)) {
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
	police.update();
	rect screen = rect(pos(0, 0), pos(gfx.ScreenWidth, gfx.ScreenHeight));
	if (!charecter.dead) {
		gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, charecter.sprite);
	}
	if (!police.dead) {
		gfx.drawsprite(police.loc.x, police.loc.y, screen, police.pic);
		gfx.drawline(police.sight);
	}
	if (!police2.dead) {
		gfx.drawsprite(police2.loc.x, police2.loc.y, screen, police2.pic);
		gfx.drawline(police2.sight);
	}
	for (int i = 0; i < bkgr.surface.size(); i++) {
		gfx.drawline(bkgr.surface.at(i));
	}
	for (int i = 0; i < bkgr.ledge.size(); i++) {
		gfx.drawline(bkgr.ledge.at(i));
	}
}
