#pragma once
#include "environment.h"
#include <string>

class codex
{
public:
	environment N[3];
	environment S[3];
	environment E[3];
	environment W[3];
	environment EW[5];
	environment NE[5];
	environment NW[5];
	environment NEW[5];
	environment SEW[5];
	environment SE[5];
	environment SW[5];
	environment NSE[5];
	environment NSW[5];
	environment NSEW[10];
	codex();
};

codex c;

/*
Legend

s = left + right
h = top + bottom
m = left + right + top
u = left + right + bottom
a = left + top
g = right + top
d = left + bottom
f = right + bottom
e = empty space
r = spike right
l = spike left
b = spike bottom
t = spike top
z = top + bottom + right
x = top + bottom + left
o = full sqare

*/

codex::codex()
{
	enemy p;
	//E
	E[0] = environment(std::string("ehhhhhhhhhhhhhheseesleeersleeeesszeseeeeeseeeeeuseesermlesermeeeseeseeseeseeseeeseruleseruleseeeseeeeeseeeeeseemsleeersleeeeseesehhhhhhhhhhhhhhe"));
	E[1] = environment(std::string("ehhhhhhhhhhhhhheseeseeseeseeseesseeseeseeseeseeuseeseeseeseeseeeseeteeteeteeteeeseeeeeeeeeeeeeeeseeeeeeeeeeeeeahsgbbbbbbbbbbbbseehhhhhhhhhhhhhhe"));
	E[2] = environment(std::string("ehhhhhhhhhhhhhhesttttttttttttttsseeeeeeeeeeeeeeuseeeeeeeeeeeeeeesleoeeeoeeeeeeeeseeeeeeeeeoeeoeeseeeeeeeeeeeeeemsgbbbbbbbbbbbbbsehhhhhhhhhhhhhhe"));
	//NE
	NE[0] = environment(std::string("ehhhhhheehhhhhhestttteeeeeettttsseeeeeeeeeeeeeeuseogeeeeeeeeaoeeseeseeeeeeeeseeeseeseeeeeeeeseeeseedoeeeeeeofeemseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.base = line(pos(64, 512), pos(960, 256));
	NE[1].police.push_back(p);
	NE[1] = environment(std::string("ehhhhhfeedhhhhheseeeeeeeeeeeeeesehhhhoeeeeeeeeeuseeeeeeeeeeeeeeeehhoeeeohhhhhoeeseeeeeeeeeeeeeeeehhhhoeeeeeeeeemseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.base = line(pos(64,128), pos(384,128));
	NE[1].police.push_back(p);
	p.base = line(pos(64,256), pos(256,256));
	NE[1].police.push_back(p);
	p.base = line(pos(64,384), pos(384,384));
	NE[1].police.push_back(p);
	NE[2] = environment(std::string("ehhhhhseeseeeeeeseseeeseeseeeeeesesemeseedhhhhhoseseseseeeeeeeeeseseseseeeeeeeeeseseseseeeeeeeeeseueseueeahhhhhoseeeseeeeseeeeeeehhhehhhhheeeeee"));
	//W
	W[0] = environment(std::string("ehhhhhhhhhhhhhheseeeersleeerseesueeeeeseeeeesexseeemlesermleseeseeeseeseeseeseeseeeseruleserulesmeeseeeeeseeeeesseeseeeersleeersehhhhhhhhhhhhhhe"));
	W[1] = environment(std::string("ehhhhhhhhhhhhhheseeseeseeseeseesueeseeseeseeseeseeeseeseeseeseeseeeteeteeteeteeseeeeeeeeeeeeeeeshgeeeeeeeeeeeeesesbbbbbbbbbbbbasehhhhhhhhhhhhhhe"));
	W[2] = environment(std::string("ehhhhhhhhhhhhhhesttttttttttttttsueeeeeeeeeeeeeeseeeeeeeeeeeeeeeseeeeeeeeoeeeoerseeoeeoeeeeeeeeesmeeeeeeeeeeeeeessbbbbbbbbbbbbbasehhhhhhhhhhhhhhe"));
	//NW
	NW[0] = environment(std::string("ehhhhhheehhhhhhestttteeeeeettttsueeeeeeeeeeeeeeseeogeeeeeeeeaoeseeeseeeeeeeeseeseeeseeeeeeeeseesmeedoeeeeeeofeesseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	NW[1] = environment(std::string("ehhhhhfeedhhhhheseeeeeeeeeeeeeesueeeeeeeeeohhhheeeeeeeeeeeeeeeeseeohhhhhoeeeohheeeeeeeeeeeeeeeesmeeeeeeeeeohhhheseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	NW[2] = environment(std::string("eeeeeeseeshhhhheeeeeeeseeseeesesohhhhhfeesemeseseeeeeeeeeseseseseeeeeeeeeseseseseeeeeeeeesesesesohhhhhgeeueseueseeeeeeseeeeseeeseeeeeehhhhhehhhe"));

	environment temp;
	temp.surface.push_back(line(pos(64, 500), pos(960, 500)));

	N[0] = temp;
	N[1] = temp;
	N[2] = temp;
	S[0] = temp;
	S[1] = temp;
	S[2] = temp;

	EW[1] = temp;
	EW[2] = temp;
	EW[3] = temp;
	EW[4] = temp;
	EW[0] = temp;

	NE[3] = temp;
	NE[4] = temp;

	NW[3] = temp;
	NW[4] = temp;

	NEW[1] = temp;
	NEW[2] = temp;
	NEW[0] = temp;
	NEW[3] = temp;
	NEW[4] = temp;

	SEW[1] = temp;
	SEW[2] = temp;
	SEW[0] = temp;
	SEW[3] = temp;
	SEW[4] = temp;

	SE[1] = temp;
	SE[2] = temp;
	SE[3] = temp;
	SE[4] = temp;
	SE[0] = temp;

	SW[1] = temp;
	SW[2] = temp;
	SW[3] = temp;
	SW[4] = temp;
	SW[0] = temp;

	NSE[1] = temp;
	NSE[2] = temp;
	NSE[3] = temp;
	NSE[4] = temp;
	NSE[0] = temp;

	NSW[1] = temp;
	NSW[2] = temp;
	NSW[3] = temp;
	NSW[4] = temp;
	NSW[0] = temp;

	NSEW[1] = temp;
	NSEW[2] = temp;
	NSEW[3] = temp;
	NSEW[4] = temp;
	NSEW[0] = temp;
	NSEW[5] = temp;
	NSEW[6] = temp;
	NSEW[7] = temp;
	NSEW[8] = temp;
	NSEW[9] = temp;
}

/*

Legend
s = left + right
h = top + bottom
m = left + right + top
u = left + right + bottom
a = left + top
g = right + top
d = left + bottom
f = right + bottom
e = empty space
r = spike right
l = spike left
b = spike bottom
t = spike top
z = top + bottom + right
x = top + bottom + left
o = full sqare


*/
