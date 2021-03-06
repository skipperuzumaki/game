#include "world.h"
#include "spritecodex.h"

void world::update(Keyboard& kbd, Graphics& gfx, float dt, bool grav)
{
	if (!paused) {
		for (int i = 0; i < bkgr.police.size(); i++) {
			if (charecter.extent.boundrycrossing(bkgr.police.at(i).die) && !charecter.dead && !bkgr.police.at(i).dead) {
				paused = true;
				dying = i;
			}
			else { bkgr.policebackup.at(i).update(dt); }
			if (charecter.extent.boundrycrossing(bkgr.police.at(i).sight) && !bkgr.police.at(i).dead && !charecter.dead) {
				paused = true;
				killer = i;
			}
		}
		for (int i = 0; i < bkgr.killzone.size(); i++) {
			if (charecter.extent.boundrycrossing(bkgr.killzone.at(i))) {
				charecter.dead = true;
			}
		}
		for (int i = 0; i < bkgr.interactibles.size(); i++) {
			if (charecter.extent.inside(bkgr.interactibles.at(i))) {
				charecter.points++;
				bkgr.interactiblesbackup.erase(bkgr.interactiblesbackup.begin() + i);
			}
		}
		if (charecter.extent.crossing(bkgr.endpoint)) {
			charecter.points += 10;
			charecter.won = true;
		}
		if (kbd.KeyIsPressed(VK_RIGHT)) {
			vx = 3.0f*60.0f*dt;
			chfac = direction::west;
		}
		if (kbd.KeyIsPressed(VK_UP)) {
			if (!upmtm) {
				vy = -4.5f*60.0f*dt;
				upmtm = true;
			}
		}
		if (kbd.KeyIsPressed(VK_LEFT)) {
			vx = -3.0f*60.0f*dt;
			chfac = direction::east;
		}
		if (kbd.KeyIsPressed(VK_DOWN)) {
			vy = 3.0f*60.0f*dt;
		}
		if (!screen.inside(charecter.pos + pos(41, 55)) || !screen.inside(charecter.pos + pos(-1, -1))) {
			vx = 0;
			vy = 0;
		}
		//movements
		if (vy > 4.5f*60.0f*dt) {
			vy = 4.5f*60.0f*dt;
		}
		else if (vy < -4.5f*60.0f*dt) {
			vy = -4.5f*60.0f*dt;
		}
		pos temp = bkgr.loc;
		bkgr.move(int(vx), int(vy));
		if (!bkgr.safe(gfx.ScreenWidth, gfx.ScreenHeight)) {
			bkgr.move(-int(vx), -int(vy));
			charecter.pos.x += int(vx);
			charecter.pos.y += int(vy);
		}
		if (charecter.pos.x > 480 && charecter.pos.x < 500 && bkgr.extent.x4 > gfx.ScreenWidth) {
			charecter.pos.x -= int(1);
			bkgr.move(int(1), 0);
		}
		else if (charecter.pos.x < 480 && charecter.pos.x > 460 && bkgr.loc.x < 0) {
			charecter.pos.x += int(1);
			bkgr.move(-int(1), 0);
		}
		else if (charecter.pos.x >= 500 && bkgr.extent.x4 > gfx.ScreenWidth) {
			charecter.pos.x -= int(3.0f*60.0f*dt);
			bkgr.move(int(3.0f*60.0f*dt), 0);
		}
		else if (charecter.pos.x <= 460 && bkgr.loc.x < 0) {
			charecter.pos.x += int(3.0f*60.0f*dt);
			bkgr.move(-int(3.0f*60.0f*dt), 0);
		}
		if (charecter.pos.y > 256 && charecter.pos.y < 276 && bkgr.extent.y4 > gfx.ScreenHeight) {
			charecter.pos.y -= int(1);
			bkgr.move(0, int(1));
		}
		else if (charecter.pos.y < 256 && charecter.pos.y > 236 && bkgr.loc.y < 0) {
			charecter.pos.y += int(1);
			bkgr.move(0, -int(1));
		}
		else if (charecter.pos.y >= 276 && bkgr.extent.y4 > gfx.ScreenHeight) {
			charecter.pos.y -= int(3.0f*60.0f*dt);
			bkgr.move(0, int(3.0f*60.0f*dt));
		}
		else if (charecter.pos.y <= 236 && bkgr.loc.y < 0) {
			charecter.pos.y += int(3.0f*60.0f*dt);
			bkgr.move(0, -int(3.0f*60.0f*dt));
		}
		//gravity keep last else inf gravity
		if (bkgr.ignoregravity(charecter)) {
			vy = 0.0f;
			vx = 0.0f;
			upmtm = false;
		}
		else { vy += 0.30f*60.0f*dt; }
	}
	if (justafterconfig) {
		paused = false;
		justafterconfig = false;
	}
}

void world::draw(Graphics & gfx ,rect screen)
{
	sprite wpol = sprites::police.getframe();
	sprite epol = wpol.fliphorizontal();
	gfx.drawsprite(bkgr.loc.x, bkgr.loc.y, screen, bkgr.level);
	gfx.drawsprite(bkgr.endpoint.start.x, bkgr.endpoint.start.y - 19, screen, exit);
	if (!charecter.dead) {
		if (dying < 0) {
			if (chfac == direction::east) {
				gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, sprites::charecter.getframe());
			}
			else {
				gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, sprites::charecter.getframe().fliphorizontal());
			}
		}
		else if (dying >= 0) {
			if (chfac == direction::east) {
				gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, sprites::charecteratk.getframe());
				if (sprites::charecteratk.getcurrent() >= sprites::charecteratk.size() - 1) {
					paused = false;
					bkgr.policebackup.at(dying).dead = true;
					dying = -1;
					sprites::charecteratk.reset();
				}
			}
			else {
				gfx.drawsprite(charecter.pos.x, charecter.pos.y, screen, sprites::charecteratk.getframe().fliphorizontal());
				if (sprites::charecteratk.getcurrent() >= sprites::charecteratk.size() - 1) {
					paused = false;
					bkgr.policebackup.at(dying).dead = true;
					dying = -1;
					sprites::charecteratk.reset();
				}
			}
		}
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
						killer = -1;
					}
				}
				else {
					gfx.drawsprite(charecter.pos.x - 64, charecter.pos.y, screen, sprites::policeatk.getframe().fliphorizontal());
					if (sprites::policeatk.getcurrent() >= sprites::policeatk.size() - 1) {
						paused = false;
						charecter.dead = true;
						killer = -1;
					}
				}
			}
		}
	}
	for (int i = 0; i < bkgr.interactibles.size(); i++) {
		auto k = bkgr.interactibles.at(i);
		if (screen.inside(k)) {
			gfx.drawline(line(k, k + pos(10, 0)), Colors::White);
		}//temp fix
	}
}

void world::reconfigure()
{
	paused = true;
	reset();
	configure();
	vy = 0;
	vx = 0;
	charecter.pos = pos(480, 256);
	justafterconfig = true;
}

void world::configure()
{
	bkgr.cleanlevel();
	bkgr.generateenvironments();
	bkgr.polbkup();
	bkgr.calcstend();
	bkgr.constructlevelsprite();
}

world::world(avatar& a, background& b)
{
	charecter = a;
	bkgr = b;
	bkgr.cleanlevel();
	bkgr.generateenvironments();
	bkgr.polbkup();
	bkgr.calcstend();
	bkgr.constructlevelsprite();
}


void world::reset()
{
	vx = 0.0f;
	vy = 0.0f;
	charecter.dead = false;
	charecter.pos = pos(480, 256);
	paused = false;
	sprites::charecter.reset();
	sprites::charecteratk.reset();
	sprites::police.reset();
	sprites::policeatk.reset();
	bkgr.reset();
}

world::~world()
{
}
