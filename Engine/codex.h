#pragma once
#include "environment.h"
#include <string>

class codex
{
public:
	environment starting;
	environment ending;
	environment NS;
	environment N;
	environment S;
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
	environment NSEW[3];
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
	temp.clear();
	//E
	temp.redefine(std::string("oooooooooooooooooeeoleeeroleeeeoooeoeeeeeoeeeeeooeeoeroleoeroeeeoeeoeeoeeoeeoeeeoeroleoeroleoeeeoeeeeeoeeeeeoeeooleeeroleeeeoeeooooooooooooooooo"));
	E[0] = temp;
	temp.redefine(std::string("oooooooooooooooooeeoeeoeeoeeoeeooeeoeeoeeoeeoeeooeeoeeoeeoeeoeeeoeeteeteeteeteeeoeeeeeeeeeeeeeeeoeeeeeeeeeeeeeoooobbbbbbbbbbbboooooooooooooooooo"));
	E[1] = temp;
	temp.redefine(std::string("ooooooooooooooooottttttttttttttooeeeeeeeeeeeeeeooeeeeeeeeeeeeeeeoleoeeeoeeeeeeeeoeeeeeeeeeoeeoeeoeeeeeeeeeeeeeeooobbbbbbbbbbbbbooooooooooooooooo"));
	E[2] = temp;
	//NE
	temp.redefine(std::string("oooooooooooooooooeeeeroleeeroeeooeeeeeoeeeeeoeooeeeoleoeroleoeeoeeeoeeoeeoeeoeeoeeeoeroleoeroleooeeoeeeeeoeeeeeooeeoeeeeroleeerooooooooooooooooo"));
	p.activate(line(pos(64, 512), pos(960, 512)));
	NE[0] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeoooooooeeeeeeeeeooeeeeeeeeeeeeeeeooooeeeoooooooeeoeeeeeeeeeeeeeeeooooooeeeeeeeeeooeeeeeeeeeeeeeeooooooooooooooooo"));
	p.activate(line(pos(64, 128), pos(384, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 256), pos(256, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 384), pos(384, 384)));
	temp.police.push_back(p);
	NE[1] = temp;
	temp.redefine(std::string("oooooooeeooooooooeoeeeoeeooooooooeoeoeoeeooooooooeoeoeoeeeeeeeeeoeoeoeoeeeeeeeeeoeoeoeoeeeeeeeeeoeoeoeoeeooooooooeeeoeeeeooooooooooooooooooooooo"));
	NE[2] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeoeeoeeeeeoooeroeeeeeeoleoooeeroeeeeeeoleeeoeerooolroooleeeoeeroeeeeeeoleeeooeroeeeeeeoleoooeeeeeoeeoeeeeeooooooooooooooooo"));
	p.activate(line(pos(64, 512), pos(384, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(640, 512), pos(960, 512)));
	temp.police.push_back(p);
	NE[3] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeoeoeeeeeeeooeeeeoeooeeeeeeeeeeeeoeeoeeeeooooooeeoeeoeeeeeeeeeeeeoeeoeeoooooooooooeooeeeeeeeeeeeeeeooooooooooooooooo"));
	p.activate(line(pos(320, 256), pos(704, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 384), pos(832, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 512), pos(960, 512)));
	temp.police.push_back(p);
	NE[4] = temp;
	//W
	temp.redefine(std::string("oooooooooooooooooeeeeroleeeroeeooeeeeeoeeeeeoeooeeeoleoeroleoeeoeeeoeeoeeoeeoeeoeeeoeroleoeroleooeeoeeeeeoeeeeeooeeoeeeeroleeerooooooooooooooooo"));
	W[0] = temp;
	temp.redefine(std::string("oooooooooooooooooeeoeeoeeoeeoeeooeeoeeoeeoeeoeeoeeeoeeoeeoeeoeeoeeeteeteeteeteeoeeeeeeeeeeeeeeeoooeeeeeeeeeeeeeooobbbbbbbbbbbboooooooooooooooooo"));
	W[1] = temp;
	temp.redefine(std::string("ooooooooooooooooottttttttttttttooeeeeeeeeeeeeeeoeeeeeeeeeeeeeeeoeeeeeeeeoeeeoeroeeoeeoeeeeeeeeeooeeeeeeeeeeeeeeoobbbbbbbbbbbbboooooooooooooooooo"));
	W[2] = temp;
	//NW
	temp.redefine(std::string("oooooooeeooooooootttteeeeeettttooeeeeeeeeeeeeeeoeeooeeeeeeeeooeoeeeoeeeooeeeoeeoeeeoeeeeeeeeoeeooeeooeeeeeeooeeooeeeeeeeeeeeeeeooooooooooooooooo"));
	p.activate(line(pos(64, 512), pos(960, 512)));
	temp.police.push_back(p);
	NW[0] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooeeeeeeeeeooooooeeeeeeeeeeeeeeeoeeoooooooeeeooooeeeeeeeeeeeeeeeooeeeeeeeeeoooooooeeeeeeeeeeeeeeooooooooooooooooo"));
	p.activate(line(pos(640, 128), pos(960, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(768, 256), pos(960, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(640, 384), pos(960, 384)));
	temp.police.push_back(p);
	NW[1] = temp;
	temp.redefine(std::string("oooooooeeooooooooooooooeeoeeeoeooooooooeeoeoeoeoeeeeeeeeeoeoeoeoeeeeeeeeeoeoeoeoeeeeeeeeeoeoeoeooooooooeeoeoeoeooooooooeeeeoeeeooooooooooooooooo"));
	NW[2] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeoeeoeeeeeoooeroeeeeeeoleooeeeroeeeeeeoleeoeeerooolroooleeoeeeroeeeeeeoleeoooeroeeeeeeoleoooeeeeeoeeoeeeeeooooooooooooooooo"));
	p.activate(line(pos(64, 512), pos(384, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(640, 512), pos(960, 512)));
	temp.police.push_back(p);
	NW[3] = temp;
	temp.redefine(std::string("oooooooeeooooooooeoeeeeeeeeeeeeooeoeeeeooeeeeeeeeeoeeeeeeeeeeeeoeeoeeooooooeeeeoeeoeeeeeeeeeeeeooeoooooooooooeeooeeeeeeeeeeeeeeooooooooooooooooo"));
	p.activate(line(pos(320, 256), pos(704, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 384), pos(832, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 512), pos(960, 512)));
	temp.police.push_back(p);
	NW[4] = temp;
	//EW
	temp.redefine(std::string("ooooooooooooooooooeeeeooooeeeeoooeeooeeooeeooeeoeeooooeeeeooooeeeooooooeeooooooeeeooooeeeeooooeeoeeooeeooeeooeeoooeeeeooooeeeeoooooooooooooooooo"));
	EW[0] = temp;
	temp.redefine(std::string("ooooooooooooooooottttttttttttttooeooooooooooooeoeeotootootootoeeeetettettetteteeeeeeeeeeeeeeeeeeoeeeeeeeeeeeeeeooobobbobbobboboooooooooooooooooo"));
	EW[1] = temp;
	temp.redefine(std::string("oooooooooooooooooeeooeeooeeooeeoooeeooeeooeeooeoeooeeooeeooeeoeeeeooeeooeeooeeeeeeeooeeooeeooeeeooeeoeeeoeeeoeeooooeeeeeeeeeeeeooooooooooooooooo"));
	EW[2] = temp;
	temp.redefine(std::string("ooooooooooooooooototottttttototooeoeeeoeeoeeeoeoeeeeeeoeeoeeeeeeeeeeeeoeeoeeeeeeeeeeoeeeeeeoeeeeoeeeoeeeeeeoeeeoobobbbbbbbbbbobooooooooooooooooo"));
	EW[3] = temp;
	temp.redefine(std::string("oooooooooooooooooeroleeeroleeeeooeeoeeeeeoeeeeeoeeeoeroleoeroleeeeeoeeoeeoeeoeeeeeroleoeroleoeeeoeeeeeoeeeeeoeeooeeeeroleeeroleooooooooooooooooo"));
	EW[4] = temp;
	//NEW
	temp.redefine(std::string("oooooooeeoooooooottttteeeetttttooeeeeeeeeeeeeeeoeeeeeeeooeeeeeeeeeeeeeeooeeeeeeeeeeeeoeooeoeeeeeooeoeoeooeoeoeoooobobobooboboboooooooooooooooooo"));
	NEW[0] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooeeeeooooooeeeeoeeeeebettebeeeeeeeeeooooooooeeeeeeeettebbetteeeeoeeooooooooooeeooeetttebbettteeooooooooooooooooo"));
	NEW[1] = temp;
	temp.redefine(std::string("oooooooeeooooooooebeoeeeeeeoebeooeoeoeoeeoeoeoeoeeoeteooooeteoeeeeoeeeooooeeeoeeeeoebeooooebeoeeoeoeoeooooeoeoeooeoeoeooooeoeoeooooooooooooooooo"));
	NEW[2] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooeoooooeeoooooeoeeeeeeeeeeeeeeeeeeeeooooooooeeeeeeeeeeeeeeeeeeeeoeoooooeeoooooeooeeeeeeeeeeeeeeooooooooooooooooo"));
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
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooooeoeooooeoeoooeeoeoeeeeeeoeoeeeeoeooooooooeoeeeeeeeeeooeeeeeeeooooooeooeoooooooeeeeeeeeeeeeeeooooooooooooooooo"));
	p.activate(line(pos(128, 512), pos(448, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(576, 512), pos(896, 512)));
	temp.police.push_back(p);
	NEW[4] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeteeeeeeteeeooooeeeooooeeeoooeeeeeeeeeeeeeeeeeeeeeooooooeeeeeeeeeeeeeeeeeeeeeoooeeeooooeeeooooeeebeeeeeebeeeooooooooooooooooo"));
	p.activate(line(pos(320, 256), pos(704, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(384, 384), pos(640, 384)));
	temp.police.push_back(p);
	NEW[5] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooeeooeeeeeeooeeoeeeeeeeeeeeeeeeeeeeeeeeooeeeeeeeeeeooeeeeeeooeeeoeeeeeeeeeeeeeeoobbbbbbbbbbbbbbooooooooooooooooo"));
	NEW[6] = temp;
	temp.redefine(std::string("oooooooeeooooooootototoeeotototooeoeoeoeeoeoeoeoeeoeoeoeeoeoeoeeeeeeoeeeeeeoeeeeeeeeeeeeeeeeeeeeoeeeeeeooeeeeeeooeeeeeeeeeeeeeeooooooooooooooooo"));
	p.activate(line(pos(62, 512), pos(960, 512)));
	temp.police.push_back(p);
	NEW[7] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeoooeooeoeeoeooeooeoeoeeoeeoeeoeoeeoooeooooooeoooeeeoeeeoeeoeeeoeeoeooeooeeooeooeooeeeeeeeeeeeeeeooooooooooooooooo"));
	NEW[8] = temp;
	temp.redefine(std::string("oooooooeeooooooooeteteteeeeeeeeooeebebeeeoooooeoeeoooooeeeteteeeeeeteteeebebebeeeebebebeeoooooeeoeoooooeeteteteooeeeeeeeeebebeeooooooooooooooooo"));
	NEW[9] = temp;
	//SEW
	temp.redefine(std::string("oooooooooooooooooeeeeeeeeeeeeeeooeolooooloooroeoeeoeeeoeeoeeeoeeeeooooorooooooeeeeoeeeoeeoeeeoeeoeolooooloooroeooeeeeeoeeoeeeeeooooooooeeooooooo"));
	SEW[0] = temp;
	temp.redefine(std::string("ooooooooooooooooottttteeeetttttooeeeeeeooeeeeeeoeeeeeeeooeeeeeeeeeobboboobobboeeeeooooooooooooeeoeoeeeeeeeeeeoeooeeebbbeebbbeeeooooooooeeooooooo"));
	SEW[1] = temp;
	temp.redefine(std::string("oooooooooooooooooeeoeeeeeeeeoeeooeeeeeeeeeeeeeeoeeeooooooooooeeeeeeeeeeeeeeeeeeeeeeooooooooooeeeoeeoeeeeeeeeoeeooeeeeeeeeeeeeeeooooooooeeooooooo"));
	p.activate(line(pos(64, 512), pos(448, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(576, 512), pos(960, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 192), pos(832, 192)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 320), pos(832, 320)));
	temp.police.push_back(p);
	SEW[2] = temp;
	temp.redefine(std::string("ooooooooooooooooottttttttttttttooeooooolroooooeoeeoeeeeeeeeeeoeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeoeeeeeeeeeeeeeeoobbbbbbeebbbbbbooooooooeeooooooo"));
	SEW[3] = temp;
	temp.redefine(std::string("oooooooooooooooooeeeeeoeeoeeeeeooooeoooeeoooeoooeeoeoeoeeoeoeoeeeeeeeeeeeeeeeeeeeeoeoeoeeoeoeoeeoooeoooeeoooeooooeeeeeoeeoeeeeeooooooooeeooooooo"));
	SEW[4] = temp;
	temp.redefine(std::string("oooooooooooooooooeeeeeeeeeeeeeeooooooooooooooeeoeeeeeeeeeeeeeeeeeeooooooooooooeeeeeeeeeeeeeeeooeooooooooooooeeoooeeeeeeeeeeeeeoooooooooeeooooooo"));
	p.activate(line(pos(64, 512), pos(448, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(576, 512), pos(896, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 128), pos(832, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(128, 256), pos(768, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 384), pos(704, 384)));
	temp.police.push_back(p);
	SEW[5] = temp;
	temp.redefine(std::string("oooooooooooooooooeeeeeeeeeeeeeeooeeoooooooooooooeeeeeeeeeeeeeeeeeeooooooooooooeeeooeeeeeeeeeeeeeooeeooooooooooooooeeeeeeeeeeeeeooooooooeeooooooo"));
	p.activate(line(pos(64, 512), pos(448, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(576, 512), pos(896, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 128), pos(960, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(128, 256), pos(768, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(256, 384), pos(768, 384)));
	temp.police.push_back(p);
	SEW[6] = temp;
	temp.redefine(std::string("oooooooooooooooooeeoeeoeeoeeoeeooeoooloroooloeeoeeeoeeoeeoeeoeeeeeeoroooloroooeeeeeeeeeeeeeeeeeeooooooeeeeooooooobbbbeeeeeettttooooooooeeooooooo"));
	SEW[7] = temp;
	temp.redefine(std::string("oooooooooooooooooeeoeeeeeeeeoeeooeeoeeeeeeeeoeeoeeeorooeeooloeeeeeeoeeoeeoeeoeeeeeeooloeeorooeeeoeeeeeoeeoeeeeeooeeeeeoeeoeeeeeooooooooeeooooooo"));
	SEW[8] = temp;
	temp.redefine(std::string("oooooooooooooooooeooeeeeeeeeooeooeeooeeeeeeooeeoeeeeeeeeeeeeeeeeeooerooeeooleooeerooerooooleooleoerooerooleooleoooeeoeeeeeeoeeoooooooooeeooooooo"));
	SEW[9] = temp;
	//SE
	temp.redefine(std::string("oooooooooooooooooeeeeeeoeeeeoleooeroeeeoeooeeeeooeroooeoeeeooleeoeeeeoeoooeeoleeoeroeoeeeeeeoleeoeroeooooooooleooeroeeeeeeeeeeeooooooooeeooooooo"));
	p.activate(line(pos(576, 128), pos(704, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(512, 256), pos(640, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(384, 384), pos(768, 384)));
	temp.police.push_back(p);
	SE[0] = temp;
	temp.redefine(std::string("oooooooooooooooooeeeetttttttoleooeroeeeeoeoeeeeooeroooeeoeoeoleeoeeeeoeeoeoeoleeoeroeobbbbbboleeoeroeooooooooleooeroeeeeeeeeeeeooooooooeeooooooo"));
	SE[1] = temp;
	temp.redefine(std::string("oooooooooooooooooeeeeeeeeeeeeooooeooooooooooeooooeoeeeeeeeeeeoeeoeoeooooooooooeeoeoeeeeeeeeeeeeeoeooooooooeeeeeooeeeeeeeeoeeeeeooooooooeeooooooo"));
	p.activate(line(pos(128, 128), pos(768, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(256, 256), pos(832, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 384), pos(640, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 512), pos(448, 512)));
	temp.police.push_back(p);
	SE[2] = temp;
	temp.redefine(std::string("oooooooooooooooooeeotottttotoeeooeeeeoeeeeoeeeeooeeeeeeooeeeeeeeoeeobbboobbboeeeoeeooooooooooeeeoeeeeeeeeeeeeeeooeeeeeeeeeeeeeeooooooooeeooooooo"));
	SE[3] = temp;
	temp.redefine(std::string("oooooooooooooooooeteoeteeoeteeeooeoeoeoeeoeoeooooeoeoeoeeoeoeoeeoeoeoeoeeoeoeoeeoeoeoeoeeoeoeoeeoooeoeoeeoeoeoeooeeeteoeeteoeteooooooooeeooooooo"));
	SE[4] = temp;
	//SW
	temp.redefine(std::string("oooooooooooooooooeroeeeeoeeeeeeooeeeeooeoeeeoleoeerooeeeoeoooleoeeroeeoooeoeeeeoeeroeeeeeeoeoleooerooooooooeoleooeeeeeeeeeeeoleooooooooeeooooooo"));
	p.activate(line(pos(320, 128), pos(448, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(384, 256), pos(512, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(238, 384), pos(640, 384)));
	temp.police.push_back(p);
	SW[0] = temp;
	temp.redefine(std::string("oooooooooooooooooerottttttteeeeooeeeeoeoeeeeoleoeeroeoeoeeoooleoeeroeoeoeeoeeeeoeerobbbbbboeoleooerooooooooeoleooeeeeeeeeeeeoleooooooooeeooooooo"));
	SW[1] = temp;
	temp.redefine(std::string("oooooooooooooooooooeeeeeeeeeeeeooooeooooooooooeoeeoeeeeeeeeeeoeoeeooooooooooeoeoeeeeeeeeeeeeeoeooeeeeeooooooooeooeeeeeoeeeeeeeeooooooooeeooooooo"));
	p.activate(line(pos(128, 128), pos(768, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 256), pos(948, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(384, 384), pos(832, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(576, 512), pos(960, 512)));
	temp.police.push_back(p);
	SW[2] = temp;
	temp.redefine(std::string("oooooooooooooooooeeotottttotoeeooeeeeoeeeeoeeeeoeeeeeeeooeeeeeeoeeeobbboobbboeeoeeeooooooooooeeooeeeeeeeeeeeeeeooeeeeeeeeeeeeeeooooooooeeooooooo"));
	SW[3] = temp;
	temp.redefine(std::string("oooooooooooooooooeeeteoeeteoeteooooeoeoeeoeoeoeoeeoeoeoeeoeoeoeoeeoeoeoeeoeoeoeoeeoeoeoeeoeoeoeooeoeoeoeeoeoeooooeteoeteeoeteeeooooooooeeooooooo"));
	SW[4] = temp;
	//NSE
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeoooooooooooooooeooeeeeeeeeeeeeeeeoeeooooooooooeeeoeeeeeeooeeeeeeeoeoooooooooooooooeeeeeeeeeeeeeeooooooooeeooooooo"));
	NSE[0] = temp;
	temp.redefine(std::string("oooooooeeooooooooloeeeeeeeeeeeeooloeoeeeeeeoeeeooloeooooooooeeeeoeeeeeeooeeeeoeeoloeooooooooeeeeoloeoeeeeeeoeeeooloeeeeeeeeeeeeooooooooeeooooooo"));
	NSE[1] = temp;
	temp.redefine(std::string("oooooooeeooooooootttttoeeeeeeeeooeeeeeooooooooeooeeeeeeeeeooooeeoeoboeeeeeeotoeeoeooooeeeeeeeeeeoeooooooooeeeeeooeeeeeeeeobbbbbooooooooeeooooooo"));
	NSE[2] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooeeeeeeeeeeeeeeooeoloeeeeeeoloeeoebeteeooeebeteeoeoroeeeeeeoroeeoeeeeeeeeeeeeeeooeeeeeeeeeeeeeeooooooooeeooooooo"));
	NSE[3] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeteeeooeeeeeeeeeeoeeeooeeeeeeeeeeoeeeeooooeoeoooooooeeoeeeeeeeeeeoeeeeoeeeeeeeeeeoeeeooeeeeeeeeeeteeeooooooooeeooooooo"));
	NSE[4] = temp;
	//NSW
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooeooooooooooooooeeeeeeeeeeeeeeeoeeeooooooooooeeoeeeeeeeooeeeeeeoooooooooooooooeooeeeeeeeeeeeeeeooooooooeeooooooo"));
	NSW[0] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeorooeeeoeeeeeeoeoroeeeeooooooooeoroeeoeeeeooeeeeeeoeeeeooooooooeorooeeeoeeeeeeoeorooeeeeeeeeeeeeorooooooooeeooooooo"));
	NSW[1] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeotttttooeooooooooeeeeeoeeooooeeeeeeeeeoeeotoeeeeeeoboeoeeeeeeeeeeooooeooeeeeeooooooooeoobbbbboeeeeeeeeooooooooeeooooooo"));
	NSW[2] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooeeeeeeeeeeeeeeoeeoroeeeeeeoroeoeetebeeooeetebeoeeoloeeeeeeoloeooeeeeeeeeeeeeeeooeeeeeeeeeeeeeeooooooooeeooooooo"));
	NSW[3] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeteeeeeeeeeeooeeeoeeeeeeeeeeoeeeeoeeeeeeeeeeoeeoooooooeoeooooeeeeoeeeeeeeeeeooeeeoeeeeeeeeeeooeeeteeeeeeeeeeooooooooeeooooooo"));
	NSW[4] = temp;
	//NSEW
	temp.redefine(std::string("oooooooeeooooooooeeoeeeeeeeeeeeooeeoooooooooeoooeeeeoeeeroeeeoeeeeoeoloeeoroeoeeeeoeeeoleeeoeeeeoooeoooooooooeeooeeeeeeeeeeeoeeooooooooeeooooooo"));
	NSEW[0] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeetooooooobeeeooobeetoooeooobeetooobeeteeetooobeetooobeeebeetooobeetoooeooobeetoooeeeeooooooobeeeeeeeeeooooooooeeooooooo"));
	NSEW[1] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooeoeeeeeeeeeeoeoeeooooooooooooeeeeottotootottoeeeeeeeeeeeeeeeeeeoeeeeeeeeeeeeeeooeebbbeeeebbbeeooooooooeeooooooo"));
	NSEW[2] = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeeeeeeeeeeooeeeoeeeeeeoeeeoeeeoooeeeeoooeeeeeooooooooooooeeeeeoooeeeeoooeeeoeeeoeeeeeeoeeeooeeeeeeooeeeeeeooooooooooooooooo"));
	ending = temp;
	temp.redefine(std::string("oooooooooooooooooeeeeeeeeeeeeeeooeeeeeeeeeeeeeeoeeeoeeeeeeeeoeeeeeeoeeeeeeeeoeeeeeeoeeeeeeeeoeeeoeeooooooooooeeooeeeeeeeeeeeeeeooooooooeeooooooo"));
	starting = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeoeeeeeoeeooeeoeeooooeeoeeooeeoeeeeeeeeeeeooeeooooooooooeeooeeeeeeeeeeeoeeooeeoeeooooeeoeeooeeoeeeeeoeeeeeooooooooeeooooooo"));
	NS = temp;
	temp.redefine(std::string("oooooooooooooooooeeeeeoeeeeeoeeooeeoeeooooeeoeeooeeoeeeeeeeeeeeooeeooooooooooeeooeeeeeeeeeeeoeeooeeoeeooooeeoeeooeeoeeeeeoeeeeeooooooooeeooooooo"));
	S = temp;
	temp.redefine(std::string("oooooooeeooooooooeeeeeoeeeeeoeeooeeoeeooooeeoeeooeeoeeeeeeeeeeeooeeooooooooooeeooeeeeeeeeeeeoeeooeeoeeooooeeoeeooeeoeeeeeoeeeeeooooooooooooooooo")); \
	N = temp;
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
