#include "background.h"
#include <algorithm>
#include "codex.h"
#include <algorithm>

background::background()
{
}



void background::updatelines()
{
	surface.clear();
	ledge.clear();
	killzone.clear();
	police.clear();
	interactibles.clear();
	int const wt = 1024;
	int const ht = 576;
	for (int i = 0; i < 25; i++) {
		pos offset = pos(wt*(i % 5), ht*(i / 5));
		for (int j = 0; j < sectors.at(i).surface.size(); j++) {
			pos p1 = (sectors.at(i).surface.at(j).start + offset) + loc;
			pos p2 = (sectors.at(i).surface.at(j).end + offset) + loc;
			line l = line(p1, p2);
			surface.push_back(l);
		}
		for (int j = 0; j < sectors.at(i).ledge.size(); j++) {
			pos p1 = (sectors.at(i).ledge.at(j).start + offset) + loc;
			pos p2 = (sectors.at(i).ledge.at(j).end + offset) + loc;
			line l = line(p1, p2);
			ledge.push_back(l);
		}
		for (int j = 0; j < sectors.at(i).killzone.size(); j++) {
			pos p1 = (sectors.at(i).killzone.at(j).start + offset) + loc;
			pos p2 = (sectors.at(i).killzone.at(j).end + offset) + loc;
			line l = line(p1, p2);
			killzone.push_back(l);
		}
	}
	for (int j = 0; j < policebackup.size(); j++) {
		enemy temp;
		temp = policebackup.at(j);
		temp.base = line((policebackup.at(j).base.start + loc), (policebackup.at(j).base.end + loc));
		temp.loc = (policebackup.at(j).loc + loc);
		temp.sight = line(policebackup.at(j).sight.start + loc, policebackup.at(j).sight.end + loc);
		temp.die= line(policebackup.at(j).die.start + loc, policebackup.at(j).die.end + loc);
		police.push_back(temp);
	}
	for (int j = 0; j < interactiblesbackup.size(); j++) {
		line l = line((interactiblesbackup.at(j).start + loc), (interactiblesbackup.at(j).end + loc));
		interactibles.push_back(l);
	}
}

bool background::ignoregravity(avatar &charecter)
{
	bool ret = false;
	charecter.extent = rect(charecter.pos, pos(charecter.pos.x + charecter.sprite.getwidth(), charecter.pos.y + charecter.sprite.getheight()));
	for (int i = 0; i < surface.size(); i++) {
		if (charecter.extent.crossing(surface.at(i))) {
			int offset1 = (surface.at(i).start.y - charecter.extent.y4);
			int offset2 = (surface.at(i).start.y - charecter.extent.y1);
			int offset;
			if (std::abs(offset1) < std::abs(offset2)) {
				offset = offset1;
			}
			else if (std::abs(offset2) < std::abs(offset1)) {
				offset = offset2;
			}
			else {
				offset = 0;
			}
			charecter.pos.y += offset;
			charecter.extent.offsety(offset);
			ret = true;
		}
	}
	for (int i = 0; i < ledge.size(); i++) {
		if (charecter.extent.crossing(ledge.at(i))) {
			int offset1 = (ledge.at(i).start.x - charecter.extent.x4);
			int offset2 = (ledge.at(i).start.x - charecter.extent.x1);
			int offset;
			if (std::abs(offset1) < std::abs(offset2)) {
				offset = offset1;
			}
			else if (std::abs(offset2) < std::abs(offset1)) {
				offset = offset2;
			}
			else {
				offset = 0;
			}
			charecter.pos.x += offset;
			charecter.extent.offsetx(offset);
			ret = true;
		}
	}
	return ret;
}

void background::generateroute()
{
	//initialisation and clearing pushbacks
	openings.clear();
	for (int i = 0; i < 25; i++) {
		std::vector<direction> k;
		openings.push_back(k);
	}
	//this does the job
	srand(int(time(NULL)));
	int q, w, e, current;
	q = rand() % 5;
	current = q;
	openings.at(current).push_back(direction::start);
	openings.at(current).push_back(direction::crit);
	//initalisation done
	w = rand() % 1;
	if (current == 0) {
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		current++;
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		w = 0;
	}
	else if (current == 4) {
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		current--;
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current==4) {
				openings.at(current).push_back(direction::south);
				openings.at(current).push_back(direction::crit);
				current += 5;
				openings.at(current).push_back(direction::north);
				openings.at(current).push_back(direction::crit);
				w = -1;
				break;
			}
			else {
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				current++;
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current==0) {
				openings.at(current).push_back(direction::south);
				openings.at(current).push_back(direction::crit);
				current += 5;
				openings.at(current).push_back(direction::north);
				openings.at(current).push_back(direction::crit);
				w = -1;
				break;
			}
			else {
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				current++;
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				w = 1;
			}
		}
	}
	//row 0 done
	w = rand() % 1;
	if (current == 5) {
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		current++;
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		w = 0;
	}
	else if (current == 9) {
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		current--;
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 9) {
				openings.at(current).push_back(direction::south);
				openings.at(current).push_back(direction::crit);
				current += 5;
				openings.at(current).push_back(direction::north);
				openings.at(current).push_back(direction::crit);
				w = -1;
				break;
			}
			else {
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				current++;
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 5) {
				openings.at(current).push_back(direction::south);
				openings.at(current).push_back(direction::crit);
				current += 5;
				openings.at(current).push_back(direction::north);
				openings.at(current).push_back(direction::crit);
				w = -1;
				break;
			}
			else {
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				current--;
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				w = 1;
			}
		}
	}
	//row 1 done
	w = rand() % 1;
	if (current == 10) {
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		current++;
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		w = 0;
	}
	else if (current == 14) {
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		current--;
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 14) {
				openings.at(current).push_back(direction::south);
				openings.at(current).push_back(direction::crit);
				current += 5;
				openings.at(current).push_back(direction::north);
				openings.at(current).push_back(direction::crit);
				w = -1;
				break;
			}
			else {
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				current++;
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 10) {
				openings.at(current).push_back(direction::south);
				openings.at(current).push_back(direction::crit);
				current += 5;
				openings.at(current).push_back(direction::north);
				openings.at(current).push_back(direction::crit);
				w = -1;
				break;
			}
			else {
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				current--;
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				w = 1;
			}
		}
	}
	//row 2 done
	w = rand() % 1;
	if (current == 15) {
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		current++;
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		w = 0;
	}
	else if (current == 19) {
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		current--;
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 19) {
				openings.at(current).push_back(direction::south);
				openings.at(current).push_back(direction::crit);
				current += 5;
				openings.at(current).push_back(direction::north);
				openings.at(current).push_back(direction::crit);
				w = -1;
				break;
			}
			else {
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				current++;
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 15) {
				openings.at(current).push_back(direction::south);
				openings.at(current).push_back(direction::crit);
				current += 5;
				openings.at(current).push_back(direction::north);
				openings.at(current).push_back(direction::crit);
				w = -1;
				break;
			}
			else {
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				current--;
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				w = 1;
			}
		}
	}
	//row 3 done
	w = rand() % 1;
	if (current == 20) {
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		current++;
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		w = 0;
	}
	else if (current == 24) {
		openings.at(current).push_back(direction::west);
		openings.at(current).push_back(direction::crit);
		current--;
		openings.at(current).push_back(direction::east);
		openings.at(current).push_back(direction::crit);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 24) {
				openings.at(current).push_back(direction::end);
				openings.at(current).push_back(direction::crit);
				break;
			}
			else {
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				current++;
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 20) {
				openings.at(current).push_back(direction::end);
				openings.at(current).push_back(direction::crit);
				break;
			}
			else {
				openings.at(current).push_back(direction::west);
				openings.at(current).push_back(direction::crit);
				current--;
				openings.at(current).push_back(direction::east);
				openings.at(current).push_back(direction::crit);
				w = 1;
			}
		}
	}
	//did it
}

bool background::hasopening(int n, direction d)
{
	for (int i = 0; i < openings.at(n).size(); i++) {
		if (openings.at(n).at(i) == d) {
			return true;
		}
	}

	return false;
}

void background::generatecontent()
{
	generateroute();
	int i, current, e, k;
	for (i = 0; i < 5; i++) {
		if (!(hasopening(i, direction::crit))) {
			current = i;
			openings.at(current).push_back(direction::west);
			current--;
			while (current > -1) {
				openings.at(current).push_back(direction::east);
				if (current != 0) {
					openings.at(current).push_back(direction::west);
				}
				e = rand() % 3;
				if (e == 0) {
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
				current--;
			}
			break;
		}
	}
	for (i = 4; i > -1; i--) {
		if (!(hasopening(i, direction::crit))) {
			current = i;
			openings.at(current).push_back(direction::east);
			current++;
			while (current < 5) {
				openings.at(current).push_back(direction::west);
				if (current != 4) {
					openings.at(current).push_back(direction::east);
				}
				e = rand() % 3;
				if (e == 0) {
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
				current++;
			}
			break;
		}
	}
	//row 0 done
	for (i = 5; i < 10; i++) {
		if (!(hasopening(i, direction::crit))) {
			current = i;
			if (current == 5) {
				e = rand() % 2;
				if (e == 0) {
					k = rand() % 2;
					if (k == 1) {
						openings.at(current).push_back(direction::south);
						openings.at(current + 5).push_back(direction::north);
					}
					else {
						openings.at(current).push_back(direction::east);
						openings.at(current + 1).push_back(direction::west);
					}
				}
				else {
					openings.at(current).push_back(direction::east);
					openings.at(current + 1).push_back(direction::west);
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
			}
			else if (current == 9) {
				e = rand() % 2;
				if (e == 0) {
					k = rand() % 2;
					if (k == 1) {
						openings.at(current).push_back(direction::south);
						openings.at(current + 5).push_back(direction::north);
					}
					else {
						openings.at(current).push_back(direction::west);
						openings.at(current - 1).push_back(direction::east);
					}
				}
				else {
					openings.at(current).push_back(direction::west);
					openings.at(current - 1).push_back(direction::east);
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
			}
			else {
				e = rand() % 3;
				if (e == 0) {
					k = rand() % 2;
					if (k == 1) {
						openings.at(current).push_back(direction::south);
						openings.at(current + 5).push_back(direction::north);
					}
					else {
						openings.at(current).push_back(direction::east);
						openings.at(current + 1).push_back(direction::west);
					}
				}
				else if (e == 1) {
					openings.at(current).push_back(direction::east);
					openings.at(current + 1).push_back(direction::west);
					openings.at(current).push_back(direction::west);
					openings.at(current - 1).push_back(direction::east);
				}
				else {
					openings.at(current).push_back(direction::east);
					openings.at(current + 1).push_back(direction::west);
					openings.at(current).push_back(direction::west);
					openings.at(current - 1).push_back(direction::east);
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
			}
		}
	}
	//row 1 done
	for (i = 10; i < 15; i++) {
		if (!(hasopening(i, direction::crit))) {
			current = i;
			if (current == 10) {
				e = rand() % 2;
				if (e == 0) {
					k = rand() % 2;
					if (k == 1) {
						openings.at(current).push_back(direction::south);
						openings.at(current + 5).push_back(direction::north);
					}
					else {
						openings.at(current).push_back(direction::east);
						openings.at(current + 1).push_back(direction::west);
					}
				}
				else {
					openings.at(current).push_back(direction::east);
					openings.at(current + 1).push_back(direction::west);
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
			}
			else if (current == 14) {
				e = rand() % 2;
				if (e == 0) {
					k = rand() % 2;
					if (k == 1) {
						openings.at(current).push_back(direction::south);
						openings.at(current + 5).push_back(direction::north);
					}
					else {
						openings.at(current).push_back(direction::west);
						openings.at(current - 1).push_back(direction::east);
					}
				}
				else {
					openings.at(current).push_back(direction::west);
					openings.at(current - 1).push_back(direction::east);
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
			}
			else {
				e = rand() % 3;
				if (e == 0) {
					k = rand() % 2;
					if (k == 1) {
						openings.at(current).push_back(direction::south);
						openings.at(current + 5).push_back(direction::north);
					}
					else {
						openings.at(current).push_back(direction::east);
						openings.at(current + 1).push_back(direction::west);
					}
				}
				else if (e == 1) {
					openings.at(current).push_back(direction::east);
					openings.at(current + 1).push_back(direction::west);
					openings.at(current).push_back(direction::west);
					openings.at(current - 1).push_back(direction::east);
				}
				else {
					openings.at(current).push_back(direction::east);
					openings.at(current + 1).push_back(direction::west);
					openings.at(current).push_back(direction::west);
					openings.at(current - 1).push_back(direction::east);
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
			}
		}
	}
	//row 2 done
	for (i = 15; i < 20; i++) {
		if (!(hasopening(i, direction::crit))) {
			current = i;
			if (current == 15) {
				e = rand() % 2;
				if (e == 0) {
					k = rand() % 2;
					if (k == 1) {
						openings.at(current).push_back(direction::south);
						openings.at(current + 5).push_back(direction::north);
					}
					else {
						openings.at(current).push_back(direction::east);
						openings.at(current + 1).push_back(direction::west);
					}
				}
				else {
					openings.at(current).push_back(direction::east);
					openings.at(current + 1).push_back(direction::west);
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
			}
			else if (current == 19) {
				e = rand() % 2;
				if (e == 0) {
					k = rand() % 2;
					if (k == 1) {
						openings.at(current).push_back(direction::south);
						openings.at(current + 5).push_back(direction::north);
					}
					else {
						openings.at(current).push_back(direction::west);
						openings.at(current - 1).push_back(direction::east);
					}
				}
				else {
					openings.at(current).push_back(direction::west);
					openings.at(current - 1).push_back(direction::east);
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
			}
			else {
				e = rand() % 3;
				if (e == 0) {
					k = rand() % 2;
					if (k == 1) {
						openings.at(current).push_back(direction::south);
						openings.at(current + 5).push_back(direction::north);
					}
					else {
						openings.at(current).push_back(direction::east);
						openings.at(current + 1).push_back(direction::west);
					}
				}
				else if (e == 1) {
					openings.at(current).push_back(direction::east);
					openings.at(current + 1).push_back(direction::west);
					openings.at(current).push_back(direction::west);
					openings.at(current - 1).push_back(direction::east);
				}
				else {
					openings.at(current).push_back(direction::east);
					openings.at(current + 1).push_back(direction::west);
					openings.at(current).push_back(direction::west);
					openings.at(current - 1).push_back(direction::east);
					openings.at(current).push_back(direction::south);
					openings.at(current + 5).push_back(direction::north);
				}
			}
		}
	}
	//row 3 done
	for (i = 20; i < 25; i++) {
		if (!(hasopening(i, direction::crit))) {
			current = i;
			openings.at(current).push_back(direction::west);
			current--;
			while (current > -1) {
				openings.at(current).push_back(direction::east);
				if (current != 0) {
					openings.at(current).push_back(direction::west);
				}
				current--;
			}
			break;
		}
	}
	for (i = 24; i > 20; i--) {
		if (!(hasopening(i, direction::crit))) {
			current = i;
			openings.at(current).push_back(direction::east);
			current++;
			while (current < 25) {
				openings.at(current).push_back(direction::west);
				if (current != 0) {
					openings.at(current).push_back(direction::east);
				}
				current++;
			}
			break;
		}
	}
}

void background::cleanlevel()
{
	generatecontent();
	std::vector<std::vector<direction>> temp = openings;
	openings.clear();
	for (int i = 0; i < 25; i++) {
		std::vector<direction> k;
		openings.push_back(k);
	}
	for (int i = 0; i < 25; i++) {
		bool north = false;
		bool south = false;
		bool east = false;
		bool west = false;
		for (int k = 0; k < temp.at(i).size(); k++) {
			if (temp.at(i).at(k) == direction::start) {
				openings.at(i).push_back(direction::start);
			}
			else if (temp.at(i).at(k) == direction::end) {
				openings.at(i).push_back(direction::end);
			}
			else if (temp.at(i).at(k) == direction::north && !north) {
				openings.at(i).push_back(direction::north);
				north = true;
			}
			else if (temp.at(i).at(k) == direction::south && !south) {
				openings.at(i).push_back(direction::south);
				south = true;
			}
			else if (temp.at(i).at(k) == direction::east && !east) {
				if (i % 5 != 4) {
					openings.at(i).push_back(direction::east);
				}
				east = true;
			}
			else if (temp.at(i).at(k) == direction::west && !west) {
				if (i % 5 != 0) {
					openings.at(i).push_back(direction::west);
				}
				west = true;
			}
		}
	}
	temp.clear();
	temp.shrink_to_fit();
	//PS this should have deleted the vector but be sure just in case
}

void background::generateenvironments()
{
	for (int i = 0; i < 25; i++) {
		if (hasopening(i, direction::east) && hasopening(i, direction::west)) {
			if (hasopening(i, direction::north) && hasopening(i, direction::south)) {
				std::random_shuffle(&c.NSEW[0], &c.NSEW[9]);
				sectors.at(i) = c.NSEW[0];
			}
			else if (hasopening(i, direction::north)) {
				std::random_shuffle(&c.NEW[0], &c.NEW[4]);
				sectors.at(i) = c.NEW[0];
			}
			else if (hasopening(i, direction::south)) {
				std::random_shuffle(&c.SEW[0], &c.SEW[4]);
				sectors.at(i) = c.SEW[0];
			}
		}
		else if (hasopening(i, direction::east)) {
			if (hasopening(i, direction::north) && hasopening(i, direction::south)) {
				std::random_shuffle(&c.NSE[0], &c.NSE[4]);
				sectors.at(i) = c.NSE[0];
			}
			else if (hasopening(i, direction::north)) {
				std::random_shuffle(&c.NE[0],&c.NE[4]);
				sectors.at(i) = c.NE[0];
			}
			else if (hasopening(i, direction::south)) {
				std::random_shuffle(&c.SE[0], &c.SE[4]);
				sectors.at(i) = c.SE[0];
			}
			
			else {
				std::random_shuffle(&c.E[0], &c.E[2]);
				sectors.at(i) = c.E[0];
			}
		}
		else if (hasopening(i, direction::west)) {
			if (hasopening(i, direction::north) && hasopening(i, direction::south)) {
				std::random_shuffle(&c.NSW[0], &c.NSW[4]);
				sectors.at(i) = c.NSW[0];
			}
			else if (hasopening(i, direction::north)) {
				std::random_shuffle(&c.NW[0], &c.NW[4]);
				sectors.at(i) = c.NW[0];
			}
			else if (hasopening(i, direction::south)) {
				std::random_shuffle(&c.SW[0], &c.SW[4]);
				sectors.at(i) = c.SW[0];
			}
			else {
				std::random_shuffle(&c.W[0], &c.W[2]);
				sectors.at(i) = c.W[0];
			}
		}
	}
}

void background::move(int vx, int vy)
{
	loc.x -= vx;
	loc.y -= vy;
	updatelines();
}

bool background::safe(int const srcwth, int const scrht)
{
	rect r = rect(pos(0, 0), pos(srcwth, scrht));
	extent = rect(loc, loc + pos(width, height));
	return extent.contains(r);
}

void background::constructlevelsprite()
{
	for (int y = 0; y < level.getheight(); y++) {
		for (int x = 0; x < level.getwidth(); x++) {
			int h = x / sectors.at(1).background.getwidth();
			int k = y / sectors.at(1).background.getheight();
			level.load(x, y, sectors.at(((k * 5) + h)).background.fetch((x - h), (y - k)));
		}
	}
}

void background::polbkup()
{
	int const wt = 1024;
	int const ht = 576;
	for (int i = 0; i < 25; i++) {
		pos offset = pos(wt*(i % 5), ht*(i / 5));
		for (int j = 0; j < sectors.at(i).police.size(); j++) {
			enemy temp;
			temp = sectors.at(i).police.at(j);
			temp.base = line((sectors.at(i).police.at(j).base.start + offset), (sectors.at(i).police.at(j).base.end + offset));
			temp.loc = (sectors.at(i).police.at(j).loc + offset);
			policebackup.push_back(temp);
		}
		for (int j = 0; j < sectors.at(i).interactibles.size(); j++) {
			line l = { sectors.at(i).interactibles.at(j).start + offset,sectors.at(i).interactibles.at(j).end + offset };
			interactiblesbackup.push_back(l);
		}
	}
}
