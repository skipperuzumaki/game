#include "world.h"



void world::update(float& vx, float& vy, bool& stnry, bool& upmtm, Keyboard& kbd, Graphics& gfx)
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
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		vx = 3.0f;
		stnry = false;
	}
	if (kbd.KeyIsPressed(VK_UP)) {
		if (!upmtm) {
			vy = -6.0f;
			upmtm = true;
			stnry = false;
		}
	}
	if (kbd.KeyIsPressed(VK_LEFT)) {
		vx = -3.0f;
		stnry = false;
	}
	if (kbd.KeyIsPressed(VK_DOWN)) {
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

void world::draw(Graphics & gfx ,rect screen)
{
	for (int i = 0; i < police.size(); i++) {
		police.at(i).update();
		if (!police.at(i).dead) {
			gfx.drawsprite(police.at(i).loc.x, police.at(i).loc.y, screen, police.at(i).pic);
			gfx.drawline(police.at(i).sight);
		}
	}
	if (!charecter.dead) {
		gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, charecter.sprite);
	}
	for (int i = 0; i < bkgr.surface.size(); i++) {
		gfx.drawline(bkgr.surface.at(i));
	}
	for (int i = 0; i < bkgr.ledge.size(); i++) {
		gfx.drawline(bkgr.ledge.at(i));
	}
}

void world::kill()
{
	for (int i = 0; i < police.size(); i++) {
		if (police.at(i).dead) {
			//TODO delete police.at(i);
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
}


world::~world()
{
}
