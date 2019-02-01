#include "background.h"
#include <algorithm>

background::background()
{
}



void background::updatelines()
{
	surface.clear();
	ledge.clear();
	int const wt = sectors.at(0).background.getwidth();
	int const ht = sectors.at(0).background.getwidth();
	for (int i = 0; i < 25; i++) {
		pos offset = pos(wt*(i % 5), ht*(i / 5));
		for (int j = 0; j < sectors.at(i).surface.size(); j++) {
			pos p1 = (sectors.at(i).surface.at(j).start + offset);
			pos p2 = (sectors.at(i).surface.at(j).end + offset);
			line l = line(p1, p2);
			surface.push_back(l);
		}
		for (int j = 0; j < sectors.at(i).ledge.size(); j++) {
			pos p1 = (sectors.at(i).ledge.at(j).start + offset);
			pos p2 = (sectors.at(i).ledge.at(j).end + offset);
			line l = line(p1, p2);
			ledge.push_back(l);
		}
	}
}

bool background::ignoregravity(avatar &charecter)
{
	//updatelines();  TODO add sector based lines
	//updating extent and lines to current frame
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

bool background::oncrit(int n)
{
	for (int i = 0; i < openings.at(n).size(); i++) {
		if (openings.at(n).at(i) == direction::crit) {
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
		if (oncrit(i)) {
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
		if (oncrit(i)) {
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
		if (oncrit(i)) {
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
		if (oncrit(i)) {
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
		if (oncrit(i)) {
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
		if (oncrit(i)) {
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
		if (oncrit(i)) {
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
				if (i % 5 != 0) {
					openings.at(i).push_back(direction::east);
				}
				east = true;
			}
			else if (temp.at(i).at(k) == direction::west && !west) {
				if (i % 5 != 4) {
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
	//TODO learn seavin and getting objects from file 
	//get environments.bin
}

bool background::safe(int const srcwth, int const scrht)
{
	rect r = rect(pos(0, 0), pos(srcwth, scrht));
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
