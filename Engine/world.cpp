#include "world.h"
#include "spritecodex.h"

void world::update(Keyboard& kbd, Graphics& gfx)
{
	if (!paused) {
		for (int i = 0; i < bkgr.police.size(); i++) {
			if (charecter.extent.crossing(bkgr.police.at(i).die) && !charecter.dead) {
				bkgr.policebackup.at(i).dead = true;
			}
			else { bkgr.policebackup.at(i).update(); }
			if (charecter.extent.crossing(bkgr.police.at(i).sight) && !bkgr.police.at(i).dead) {
				paused = true;
				killer = i;
			}
		}
		for (int i = 0; i < bkgr.killzone.size(); i++) {
			if (charecter.extent.crossing(bkgr.killzone.at(i))) {
				charecter.dead = true;
			}
		}
		for (int i = 0; i < bkgr.interactibles.size(); i++) {
			if (charecter.extent.crossing(bkgr.interactibles.at(i))) {
				charecter.points++;
				bkgr.interactiblesbackup.erase(bkgr.interactiblesbackup.begin() + i);
			}
		}
		if (charecter.extent.crossing(bkgr.endpoint)) {
			charecter.points += 10;
			charecter.won = true;
		}
		if (kbd.KeyIsPressed(VK_RIGHT)) {
			vx = 3.0f;
		}
		if (kbd.KeyIsPressed(VK_UP)) {
			if (!upmtm) {
				vy = -6.0f;
				upmtm = true;
			}
		}
		if (kbd.KeyIsPressed(VK_LEFT)) {
			vx = -3.0f;
		}
		if (kbd.KeyIsPressed(VK_DOWN)) {
			vy = 3.0f;
		}
		//movements
		bkgr.move(int(vx), int(vy));
		if (!bkgr.safe(gfx.ScreenWidth, gfx.ScreenHeight)) {
			bkgr.move(-int(vx), -int(vy));
			charecter.pos.x += int(vx);
			charecter.pos.y += int(vy);
		}
		if (charecter.pos.x > 480 && bkgr.extent.x4 > gfx.ScreenWidth) {
			charecter.pos.x -= 1;
			bkgr.move(1, 0);
		}
		else if (charecter.pos.x < 480 && bkgr.loc.x < 0) {
			charecter.pos.x += 1;
			bkgr.move(-1, 0);
		}
		if (charecter.pos.y > 256 && bkgr.extent.y4 > gfx.ScreenHeight) {
			charecter.pos.y -= 1;
			bkgr.move(0, 1);
		}
		else if (charecter.pos.y < 256 && bkgr.loc.y < 0) {
			charecter.pos.y += 1;
			bkgr.move(0, -1);
		}
		//gravity keep last else inf gravity
		if (bkgr.ignoregravity(charecter)) {
			vy = 0.0f;
			vx = 0.0f;
			upmtm = false;
		}
		else { vy += 0.15; }//seems fine enough
	}
}

void world::draw(Graphics & gfx ,rect screen)
{
	sprite wpol = sprites::police.getframe();
	sprite epol = wpol.fliphorizontal();
	gfx.drawsprite(0, 0, sprites::castle_bg);
	if (!charecter.dead) {
		gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, sprites::charecter.getframe());
	}
	for (int i = 0; i < bkgr.police.size(); i++) {
		if (!bkgr.police.at(i).dead) {
			if (i != killer) {
				if (bkgr.police.at(i).facing == direction::west) {
					gfx.drawsprite(bkgr.police.at(i).loc.x, bkgr.police.at(i).loc.y, screen, wpol);
				}
				else {
					gfx.drawsprite(bkgr.police.at(i).loc.x, bkgr.police.at(i).loc.y, screen, epol);
				}
			}
			else if (i == killer) {
				if (bkgr.police.at(i).facing == direction::west) {
					gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, sprites::policeatk.getframe());
					if (sprites::policeatk.getcurrent() >= sprites::policeatk.size() - 1) {
						paused = false;
						charecter.dead = true;
					}
				}
				else {
					gfx.drawsprite(charecter.pos.x - 64, charecter.pos.y, screen, sprites::policeatk.getframe().fliphorizontal());
					if (sprites::policeatk.getcurrent() >= sprites::policeatk.size() - 1) {
						paused = false;
						charecter.dead = true;
					}
				}
			}
			//gfx.drawline(bkgr.police.at(i).sight);
			//gfx.drawline(bkgr.police.at(i).die);
		}
	}
	for (int i = 0; i < bkgr.surface.size(); i++) {
		gfx.drawline(bkgr.surface.at(i),Colors::Green);
	}
	for (int i = 0; i < bkgr.ledge.size(); i++) {
		gfx.drawline(bkgr.ledge.at(i),Colors::Blue);
	}
	for (int i = 0; i < bkgr.interactibles.size(); i++) {
		gfx.drawline(bkgr.interactibles.at(i), Colors::Gray);
	}
	for (int i = 0; i < bkgr.killzone.size(); i++) {
		gfx.drawline(bkgr.killzone.at(i));
	}
	gfx.drawline(bkgr.endpoint, Colors::Cyan);
}

void world::kill()
{
	if (charecter.dead) {
		paused = false;
		sprites::charecter.reset();
		sprites::police.reset();
		sprites::policeatk.reset();
		vx = 0.0f;
		vy = 0.0f;
		charecter.dead = false;
		bkgr.loc = pos(0, 0);
		bkgr.level = sprites::gameover;
		charecter.pos = pos(480, 256);
		bkgr.killzone.clear();
		bkgr.ledge.clear();
		bkgr.policebackup.clear();
		bkgr.police.clear();
		bkgr.surface.clear();
		bkgr.sectors.clear();
		bkgr.interactiblesbackup.clear();
		environment temp, temp2;
		temp.surface.push_back({ pos(64,64),pos(960,64) });
		temp.surface.push_back({ pos(64,512),pos(960,512) });
		temp.ledge.push_back({ pos(64,64),pos(64,512) });
		temp.ledge.push_back({ pos(960,64),pos(960,512) });
		bkgr.epbkup = line(pos(128, 448), pos(128, 576));
		bkgr.sectors.push_back(temp);
		for (int i = 0; i < 24; i++) {
			bkgr.sectors.push_back(temp2);
		}
		//charecter.points.display();
		charecter.points=0;
	}
	else if (charecter.won) {
		vx = 0.0f;
		vy = 0.0f;
		charecter.pos = pos(480, 256);
		bkgr.loc = pos(0, 0);
		charecter.won = false;
		bkgr.killzone.clear();
		bkgr.ledge.clear();
		bkgr.policebackup.clear();
		bkgr.interactiblesbackup.clear();
		bkgr.police.clear();
		bkgr.surface.clear();
		bkgr.sectors.clear();
		bkgr.cleanlevel();
		bkgr.generateenvironments();
		bkgr.polbkup();
		bkgr.calcstend();
		bkgr.constructlevelsprite();
	}
}

world::world(avatar& a, background& b)
{
	charecter = a;
	bkgr = b;
	vx = 0.0f;
	vy = 0.0f;
	charecter.dead = false;
	bkgr.loc = pos(0, 0);
	bkgr.level = sprites::gameover;
	charecter.pos = pos(480, 256);
	bkgr.killzone.clear();
	bkgr.ledge.clear();
	bkgr.policebackup.clear();
	bkgr.police.clear();
	bkgr.surface.clear();
	bkgr.sectors.clear();
	bkgr.interactiblesbackup.clear();
	environment temp, temp2;
	temp.surface.push_back({ pos(64,64),pos(960,64) });
	temp.surface.push_back({ pos(64,512),pos(960,512) });
	temp.ledge.push_back({ pos(64,64),pos(64,512) });
	temp.ledge.push_back({ pos(960,64),pos(960,512) });
	bkgr.epbkup = line(pos(128, 448), pos(128, 576));
	bkgr.sectors.push_back(temp);
	for (int i = 0; i < 24; i++) {
		bkgr.sectors.push_back(temp2);
	}
	charecter.points = 0;
}


world::~world()
{
}
