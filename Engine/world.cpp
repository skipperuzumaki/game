#include "world.h"



void world::update(float& vx, float& vy, bool& upmtm, Keyboard& kbd, Graphics& gfx)
{
	for (int i = 0; i < police.size(); i++) {
		if (charecter.extent.crossing(police.at(i).die) && !charecter.dead) {
			police.at(i).dead = true;
		}
		else { police.at(i).update(); }
		if (charecter.extent.crossing(police.at(i).sight) && !police.at(i).dead) {
			charecter.dead = true;
		}
	}
	for (int i = 0; i < bkgr.killzone.size(); i++) {
		if (charecter.extent.crossing(bkgr.killzone.at(i))) {
			charecter.dead = true;
		}
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
		//interaction button
	}
	//after updating everything else
	if  (bkgr.safe(gfx.ScreenHeight, gfx.ScreenHeight)) {
		bkgr.move(int(vx), int(vy));
	}
	else if (bkgr.loc.x >= 0 || bkgr.loc.y >= 0) {
		if (kbd.KeyIsPressed(VK_RIGHT)) {
			bkgr.move(int(vx), 0);
		}
		else{ charecter.pos.x += int(vx); }
		if (vy < 0) {
			bkgr.move(0, int(vy));
		}
		else{ charecter.pos.y += int(vy); }
	}
	else if (bkgr.loc.x <= gfx.ScreenWidth && bkgr.loc.y <= gfx.ScreenHeight) {
		if (kbd.KeyIsPressed(VK_LEFT)) {
			bkgr.move(int(vx), 0);
		}
		else { charecter.pos.x += int(vx); }
		if (vy > 0) {
			bkgr.move(0, int(vy));
		}
		else { charecter.pos.y += int(vy); }
	}
	else {
		charecter.pos.x += int(vx);
		charecter.pos.y += int(vy);
	}
	if (bkgr.ignoregravity(charecter)) {
		vy = 0.0f;
		vx = 0.0f;
		upmtm = false;
	}
	else { vy += 0.15; }//seems fine enough
}

void world::draw(Graphics & gfx ,rect screen)
{
	for (int i = 0; i < police.size(); i++) {
		police.at(i).update();
		gfx.drawsprite(police.at(i).loc.x, police.at(i).loc.y, screen, police.at(i).pic);
		gfx.drawline(police.at(i).sight);
	}
	if (!charecter.dead) {
		gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, charecter.sprite);
	}
	for (int i = 0; i < bkgr.surface.size(); i++) {
		gfx.drawline(bkgr.surface.at(i),Colors::Green);
	}
	for (int i = 0; i < bkgr.ledge.size(); i++) {
		gfx.drawline(bkgr.ledge.at(i),Colors::Blue);
	}
	for (int i = 0; i < bkgr.killzone.size(); i++) {
		gfx.drawline(bkgr.killzone.at(i));
	}
}

void world::kill()
{
	for (int i = 0; i < police.size(); i++) {
		if (police.at(i).dead) {
			police.erase(police.begin() + i);
		}
	}
	if (charecter.dead) {
		//TODO game over screen
	}
}

world::world(avatar& a, std::vector<enemy>& p, background& b)
{
	charecter = a;
	police = p;
	bkgr = b;
	bkgr.cleanlevel();
	charecter.mksprite();
	for (int i = 0; i < police.size(); i++) {
		police.at(i).mksprite();
	}
}


world::~world()
{
}
