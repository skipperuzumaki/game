#include "background.h"

background::background()
{
}

void background::generateroute()
{
	//initialisation and clearing pushbacks
	for (int i = 0; i < 25; i++) {
		std::vector<direction> k;
		openings->push_back(k);
	}
	//this does the job
	srand(int(time(NULL)));
	int q, w, e, current, last;
	q = rand() % 5;
	current = q;
	openings->at(current).push_back(direction::start);
	//initalisation done
	w = rand() % 1;
	if (current == 0) {
		openings->at(current).push_back(direction::east);
		last = current;
		current++;
		openings->at(current).push_back(direction::west);
		w = 0;
	}
	else if (current == 4) {
		openings->at(current).push_back(direction::west);
		last = current;
		current--;
		openings->at(current).push_back(direction::east);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current==4) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::east);
				last = current;
				current++;
				openings->at(current).push_back(direction::west);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current==0) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::west);
				last = current;
				current++;
				openings->at(current).push_back(direction::east);
				w = 1;
			}
		}
	}
	//row 0 done
	w = rand() % 1;
	if (current == 5) {
		openings->at(current).push_back(direction::east);
		last = current;
		current++;
		openings->at(current).push_back(direction::west);
		w = 0;
	}
	else if (current == 9) {
		openings->at(current).push_back(direction::west);
		last = current;
		current--;
		openings->at(current).push_back(direction::east);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 9) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::east);
				last = current;
				current++;
				openings->at(current).push_back(direction::west);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 5) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::west);
				last = current;
				current++;
				openings->at(current).push_back(direction::east);
				w = 1;
			}
		}
	}
	//row 1 done
	w = rand() % 1;
	if (current == 10) {
		openings->at(current).push_back(direction::east);
		last = current;
		current++;
		openings->at(current).push_back(direction::west);
		w = 0;
	}
	else if (current == 14) {
		openings->at(current).push_back(direction::west);
		last = current;
		current--;
		openings->at(current).push_back(direction::east);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 14) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::east);
				last = current;
				current++;
				openings->at(current).push_back(direction::west);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 10) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::west);
				last = current;
				current++;
				openings->at(current).push_back(direction::east);
				w = 1;
			}
		}
	}
	//row 2 done
	w = rand() % 1;
	if (current == 15) {
		openings->at(current).push_back(direction::east);
		last = current;
		current++;
		openings->at(current).push_back(direction::west);
		w = 0;
	}
	else if (current == 19) {
		openings->at(current).push_back(direction::west);
		last = current;
		current--;
		openings->at(current).push_back(direction::east);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 19) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::east);
				last = current;
				current++;
				openings->at(current).push_back(direction::west);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 15) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::west);
				last = current;
				current++;
				openings->at(current).push_back(direction::east);
				w = 1;
			}
		}
	}
	//row 3 done
	w = rand() % 1;
	if (current == 20) {
		openings->at(current).push_back(direction::east);
		last = current;
		current++;
		openings->at(current).push_back(direction::west);
		w = 0;
	}
	else if (current == 24) {
		openings->at(current).push_back(direction::west);
		last = current;
		current--;
		openings->at(current).push_back(direction::east);
		w = 1;
	}
	if (w == 0) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 24) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::east);
				last = current;
				current++;
				openings->at(current).push_back(direction::west);
				w = 0;
			}
		}
	}
	else if (w == 1) {
		while (true) {
			e = rand() % 2;
			if (e == 0 || current == 20) {
				openings->at(current).push_back(direction::south);
				last = current;
				current += 5;
				openings->at(current).push_back(direction::north);
				w = -1;
				break;
			}
			else {
				openings->at(current).push_back(direction::west);
				last = current;
				current++;
				openings->at(current).push_back(direction::east);
				w = 1;
			}
		}
	}
	//should be done
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
			int h = x / sectors->at(1).background.getwidth();
			int k = y / sectors->at(1).background.getheight();
			level.load(x, y, sectors->at(((k * 5) + h)).background.fetch((x - h), (y - k)));
		}
	}
}
