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
	environment NEW[10];
	environment SEW[10];
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
	environment temp;
	//E
	temp.redefine(std::string("ehhhhhhhhhhhhhheseesleeersleeeesszeseeeeeseeeeeuseesermlesermeeeseeseeseeseeseeeseruleseruleseeeseeeeeseeeeeseemsleeersleeeeseesehhhhhhhhhhhhhhe"));
	E[0] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeseeseeseeseesseeseeseeseeseeuseeseeseeseeseeeseeteeteeteeteeeseeeeeeeeeeeeeeeseeeeeeeeeeeeeahsgbbbbbbbbbbbbseehhhhhhhhhhhhhhe"));
	E[1] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhhesttttttttttttttsseeeeeeeeeeeeeeuseeeeeeeeeeeeeeesleoeeeoeeeeeeeeseeeeeeeeeoeeoeeseeeeeeeeeeeeeemsgbbbbbbbbbbbbbsehhhhhhhhhhhhhhe"));
	E[2] = temp;
	//NE
	temp.redefine(std::string("ehhhhhoeeohhhhhestttteeeeeettttsseeeeeeeeeeeeeeuseogeeeeeeeeaoeeseeseeeeeeeeseeeseeseeeeeeeeseeeseedoeeeeeeofeemseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(64, 512), pos(960, 512)));
	temp.police.push_back(p);
	NE[0] = temp;
	temp.redefine(std::string("ehhhhhfeedhhhhheseeeeeeeeeeeeeesehhhhoeeeeeeeeeuseeeeeeeeeeeeeeeehhoeeeohhhhhoeeseeeeeeeeeeeeeeeehhhhoeeeeeeeeemseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(64,128), pos(384,128)));
	temp.police.push_back(p);
	p.activate(line(pos(64,256), pos(256,256)));
	temp.police.push_back(p);
	p.activate(line(pos(64,384), pos(384,384)));
	temp.police.push_back(p);
	NE[1] = temp;
	temp.redefine(std::string("ehhhhhseeseeeeeeseseeeseeseeeeeesesemeseedhhhhhoseseseseeeeeeeeeseseseseeeeeeeeeseseseseeeeeeeeeseueseueeahhhhhoseeeseeeeseeeeeeehhhehhhhheeeeee"));
	NE[2] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeueeueeeeesezermeeeeeemlexfseerseeeeeesleeeseershzlrxhsleeeseerseeeeeesleeeezermeeeeeemlexfseeeeemeemeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(64, 512), pos(384, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(640, 512), pos(960, 512)));
	temp.police.push_back(p);
	NE[3] = temp;
	temp.redefine(std::string("ehhhhhoeeohhheheseeeeeeeeeeeesesseeeeeexzeeeeseuseeeeeeeeeeeeseeseeeexhhhhzeeseeseeeeeeeeeeeeseeseexhhhhhhhhhfemseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(320, 256), pos(704, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 384), pos(832, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 512), pos(960, 512)));
	temp.police.push_back(p);
	NE[4] = temp;
	//W
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeersleeerseesueeeeeseeeeesexseeemlesermleseeseeeseeseeseeseeseeeseruleserulesmeeseeeeeseeeeesseeseeeersleeersehhhhhhhhhhhhhhe"));
	W[0] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeseeseeseeseesueeseeseeseeseeseeeseeseeseeseeseeeteeteeteeteeseeeeeeeeeeeeeeeshgeeeeeeeeeeeeesesbbbbbbbbbbbbasehhhhhhhhhhhhhhe"));
	W[1] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhhesttttttttttttttsueeeeeeeeeeeeeeseeeeeeeeeeeeeeeseeeeeeeeoeeeoerseeoeeoeeeeeeeeesmeeeeeeeeeeeeeessbbbbbbbbbbbbbasehhhhhhhhhhhhhhe"));
	W[2] = temp;
	//NW
	temp.redefine(std::string("ehhhhhoeeohhhhhestttteeeeeettttsueeeeeeeeeeeeeeseeogeeeeeeeeaoeseeeseeeeeeeeseeseeeseeeeeeeeseesmeedoeeeeeeofeesseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(64, 512), pos(960, 512)));
	temp.police.push_back(p);
	NW[0] = temp;
	temp.redefine(std::string("ehhhhhfeedhhhhheseeeeeeeeeeeeeesueeeeeeeeeohhhheeeeeeeeeeeeeeeeseeohhhhhoeeeohheeeeeeeeeeeeeeeesmeeeeeeeeeohhhheseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(640, 128), pos(960, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(768, 256), pos(960, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(640, 384), pos(960, 384)));
	temp.police.push_back(p);
	NW[1] = temp;
	temp.redefine(std::string("eeeeeeseeshhhhheeeeeeeseeseeesesohhhhhfeesemeseseeeeeeeeeseseseseeeeeeeeeseseseseeeeeeeeesesesesohhhhhgeeueseueseeeeeeseeeeseeeseeeeeehhhhhehhhe"));
	NW[2] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeueeueeeeesdzermeeeeeemlexeeeerseeeeeesleeseeershzlrxhsleeseeerseeeeeesleesdzerueeeeeeulexeseeeeemeemeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(64, 512), pos(384, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(640, 512), pos(960, 512)));
	temp.police.push_back(p);
	NW[3] = temp;
	temp.redefine(std::string("ehehhhoeeohhhhheseseeeeeeeeeeeesueseeeexzeeeeeeseeseeeeeeeeeeeeseeseexhhhhzeeeeseeseeeeeeeeeeeesmedhhhhhhhhhzeesseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(320, 256), pos(704, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 384), pos(832, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 512), pos(960, 512)));
	temp.police.push_back(p);
	NW[4] = temp;
	//NEW
	temp.redefine(std::string("ehhhhhoeeohhhhhesttttteeeetttttsueeeeeeeeeeeeeeueeeeeeeageeeeeeeeeeeeeesseeeeeeeeeeeemessemeeeeeagemesessesemeoaesbsbsbssbsbsbseeehhhhhhhhhhhhee"));
	NEW[0] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesueeeexhhhhzeeeeueeeeebettebeeeeeeeeexhhhhhhzeeeeeeeettebbetteeeemeexhhhhhhhhzeemseetttebbettteesehhhhhhhhhhhhhhe"));
	NEW[1] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhhesebeseeeeeesebesuemeuembbmeuemeueeseteshhseteseeeeseeeseeseeeseeeesebeseesebeseemesemeseesemesemseseseseeseseseseheheheeeehehehe"));
	NEW[2] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesuexhhhzeexhhhzeueeeeeeeeeeeeeeeeeeeexhhhhhhzeeeeeeeeeeeeeeeeeeeemexhhhzeexhhhzemseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(128, 128), pos(448, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(576, 128), pos(896, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(256, 256), pos(768, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(128, 384), pos(448, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(576, 384), pos(896, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 512), pos(960, 512)));
	temp.police.push_back(p);
	NEW[3] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesdhgemexhhzemeahfeeseseeeeeeseseeeeuedhhhhhhfeueeeeeeeeesseeeeeeeahhhhzessexhhhhgseeeeeesseeeeeesehhhhhheehhhhhhe"));
	p.activate(line(pos(128, 512), pos(448, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(576, 512), pos(896, 512)));
	temp.police.push_back(p);
	NEW[4] = temp;
	
	temp.clear();
	temp.surface.push_back(line(pos(64, 500), pos(960, 500)));
	temp.ledge.push_back(line(pos(64,64), pos(64,500)));

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

	NEW[5] = temp;
	NEW[6] = temp;
	NEW[7] = temp;
	NEW[8] = temp;
	NEW[9] = temp;

	SEW[1] = temp;
	SEW[2] = temp;
	SEW[0] = temp;
	SEW[3] = temp;
	SEW[4] = temp;
	SEW[5] = temp;
	SEW[6] = temp;
	SEW[7] = temp;
	SEW[8] = temp;
	SEW[9] = temp;

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
