#pragma once
#include "environment.h"
#include <string>

class codex
{
public:
	environment starting;
	environment ending;
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
	p.activate(line(pos(64, 128), pos(384, 128)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 256), pos(256, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 384), pos(384, 384)));
	temp.police.push_back(p);
	NE[1] = temp;
	temp.redefine(std::string("ehhhhhseeseeeeeeseseeeseeseeeeeesesemeseedhhhhhoseseseseeeeeeeeeseseseseeeeeeeeeseseseseeeeeeeeeseueseueeahhhhhoseeeseeeeseeeeeeehhhehhhhheeeeee"));
	NE[2] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeueeueeeeesezermeeeeeemlexfseerseeeeeesleeeseershzlrxhsleeeseerseeeeeesleeeezerueeeeeeulexoseeeeemeemeeeeesehhhhhhhhhhhhhhe"));
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
	temp.redefine(std::string("ehhhhhoeeshhhhheeeeeeeseeseeesesohhhhhfeesemeseseeeeeeeeeseseseseeeeeeeeeseseseseeeeeeeeesesesesohhhhhgeeueseueseeeeeeseeeeseeeseeeeeehhhhhehhhe"));
	NW[2] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeueeueeeeesdzermeeeeeemlexeeeerseeeeeesleeseeershzlrxhsleeseeerueeeeeeuleesozerueeeeeeuleoeseeeeemeemeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(64, 512), pos(384, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(640, 512), pos(960, 512)));
	temp.police.push_back(p);
	NW[3] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseseeeeeeeeeeeesueseeeexzeeeeeeseeseeeeeeeeeeeeseeseexhhhhzeeeeseeseeeeeeeeeeeesmedhhhhhhhhhzeesseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(320, 256), pos(704, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 384), pos(832, 384)));
	temp.police.push_back(p);
	p.activate(line(pos(64, 512), pos(960, 512)));
	temp.police.push_back(p);
	NW[4] = temp;
	//EW
	temp.redefine(std::string("eehhhhhhhhhhhheeeoeeeeoeeoeeeeoeueemmeeuueemmeeueemeemeeeemeemeeexeeeezeexeeeezeeeueeueeeeueeueemeeuueemmeeuueemeoeeeeoeeoeeeeoeeehhhhhhhhhhhhee"));
	EW[0] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhhesttttttttttttttsueahhhhhhhhhhgeueeutuutuutuutueeeetettettetteteeeeeeeeeeeeeeeeeemeeeeeeeeeeeeeemegbmbbmbbmbbmbaeeeeeeeeeeeeeeeee"));
	EW[1] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeooeeooeeooeesooeeooeeooeeooeueooeeooeeooeeoeeeeooeeooeeooeeeeeeeooeeooeeooeeeooeeoeeeoeeeoeemeeoeeeeeeeeeeeeseeehhhhhhhhhhhhe"));
	EW[2] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheststuttttttutstsueueeemeemeeeueueeeeeeseeseeeeeeeeeeeeueeueeeeeeeeeemeeeeeemeeeemeeeueeeeeeueeemsbmbbbbbbbbbbmbseeeeeeeeeeeeeeee"));
	EW[3] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhhesersleeersleeeesueeseeeeeseeeeeueeesermlesermleeeeeseeseeseeseeeeeruleseruleseeemeeeeeseeeeeseemseeeersleeerslesehhhhhhhhhhhhhhe"));
	EW[4] = temp;
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
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeteeeeeeteeesdhzeeexhhzeeexhfeeeeeeeeeeeeeeeeeeeeexhhhhzeeeeeeeeeeeeeeeeeeeeedhzeeexhhzeeexhfseeebeeeeeebeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(320, 256), pos(704, 256)));
	temp.police.push_back(p);
	p.activate(line(pos(384, 384), pos(640, 384)));
	temp.police.push_back(p);
	NEW[5] = temp;
	temp.redefine(std::string("ehhhhhzeexhhhhheseeeeeeeeeeeeeesueeooeeeeeeooeeueeeeeeeeeeeeeeeeeeeeeeeooeeeeeeeeeeooeeeeeeooeeemeeeeeeeeeeeeeemsbbbbbbbbbbbbbbsehhhhhhhhhhhhhhe"));
	NEW[6] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhhestststseestststsueseseseeseseseueeueseueeueseueeeeeeueeeeeeueeeeeeeeeeeeeeeeeeeemeeeeeeooeeeeeemseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	p.activate(line(pos(62, 512), pos(960, 512)));
	temp.police.push_back(p);
	NEW[7] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesooeooeoeeoeooeooeseseeseeseeseseeohoeoehheoeohoeeeseeeseeseeeseemeooeooeeooeooemseeeeeeeeeeeeeesehhhhhhhhhhhhhhe"));
	NEW[8] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseteteteeeeeeeesueebebeeeohhhoeueeohhhoeeeteteeeeeeteteeebebebeeeebebebeeohhhoeemeohhhoeetetetemseeeeeeeeebebeesehhhhhhhhhhhhhhe"));
	NEW[9] = temp;
	//SEW
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeeeeeeeeeeeesuemlxhhzlahormeueeseeeseeseeeseeeeshhhsrxehhhseeeeseeeseeseeeseemeulxhezlshzruemseeeeeseeseeeeesehhhhhoeeohhhhhe"));
	SEW[0] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhhesttttteeeetttttsueeeeeemmeeeeeeueeeeeeesseeeeeeeeembbmbssbmbbmeeeeshhhhhhhhhhseemeueeeeeeeeeeuemseeebbbeebbbeeesehhheeseeseehhhe"));
	SEW[1] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhehheseeueeeeeeeeueesueeeeeeeeeeeeeeueeexhhhhhhhhzeeeeeeeeeeeeeeeeeeeeeeahhhhhhhhgeeemeeueeeeeeeeueemseeeeeeeeeeeeeesehhhhhoeeohhhhhe"));
	p.activate(line(pos(64, 512), pos(448, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(576, 512), pos(960, 512)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 192), pos(832, 192)));
	temp.police.push_back(p);
	p.activate(line(pos(192, 320), pos(832, 320)));
	temp.police.push_back(p);
	SEW[2] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhhesttttttttttttttsueahhhzlrxhhhgeueeueeeeeeeeeeueeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeembbbbbbeebbbbbbmeeeeeeseeseeeeeeeeeeeeseeseeeeee"));
	SEW[3] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeeeseeseeeeesdhgeahfeedhgeahfeeueueueeueueueeeeeeeeeeeeeeeeeeeemememeemememeeahfedhseeshfedhgseeeeeseeseeeeesehhhhhoeeohhhhhe"));
	SEW[4] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeeeeeeeeeeeesuhhhhhhhhhhhoeeueeeeeeeeeeeeeeeeeeohhhhhhhhhhoeeeeeeeeeeeeeeeomeohhhhhhhhhhoeesmseeeeeeeeeeeeeseehhhhhoeeohhhhhe"));
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
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeeeeeeeeeeeesueeohhhhhhhhhhhueeeeeeeeeeeeeeeeeeohhhhhhhhhhoeeemoeeeeeeeeeeeeemseeohhhhhhhhhhoeseeeeeeeeeeeeesehhhhhoeeohhhhhe"));
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
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeseeseeseeseesueoeolsroeolseeueeeseeseeseeseeeeeeuroholurohoeeeeeeeeeeeeeeeeeeohhhhoeeeeohhhhosbbbbeeeeetttttseeeeehoeeohhhhhe"));
	SEW[7] = temp;
	temp.redefine(std::string("ehhhhhhhhhheeeeeeeeeoeeeeeeoeeeeohhoeeeeeeeeohhoeeesrooeeoolseeeeeeseeseeseeseeeeeeoolseesrooeeemeeeeeseeseeeeemehhhhhseeshhhhheeeeeeeoeeoeeeeee"));
	SEW[8] = temp;
	temp.redefine(std::string("ehhhhhhhhhhheeheseoseeeeeeeesoesueeuoeeeeeeoueeoeeeeeeeeeeeeeeeeeooerooeeooleooeeruoeruhhuleoulemeruoeruuleoulememeeseeeeeeseemeeehhehoeeohehhee"));
	SEW[9] = temp;
	//SE
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeeeeseeeeslessermeeeseooeeeeuseruhmeseeeomleeseeeeseuhoeesleesermeseeeeeesleeserseuhhhhhhmlemserseeeeeeeeeeesehhehhoeeohhhhhe"));
	SE[0] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeettttttttulessrmeeemememeeeeusruhmesesesemleeseeeseueueuesleesrmesbbbbbbbsleesrseuhhhhhhhulemsrseeeeeeeeeeeesehehhhoeeohhhhhe"));
	SE[1] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeeeeeeeeeeseeseuhhhhhhhhoeshuseseeeeeeeeeeseeseseohhhhhhhhueeseseeeeeeeeeeeeeseuhhhhhhmeeeeemseeeeeeeeseeeeesehhhhhoeeohhhhhe"));
	SE[2] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeutsttttstueesseeeeueeeeueeeeuseeeeeemmeeeeeeeseembbbssbbbmeeeseeuhhhhhhhhueeeseeeeeeeeeeeeeemseeeeeeeeeeeeeesehhhhhoeeohhhhhe"));
	SE[3] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeseeeeseeeeessemesemeesememhuseseseseeseseseeseseseseeseseseeseseseseeseseseeehueueseeueseuemseeeeeseeeeseeesehhhhhoeeohhhhhe"));
	SE[4] = temp;
	//SW
	temp.redefine(std::string("ehhehhhhhhhhhhheserseeeeseeeeeesueeeeooeseeemleseermoeeesemhuleseerseeohueseeeeseerseeeeeesemlesmermhhhhhhueslesseeeeeeeeeeeslesehhhhhoeeohhehhe"));
	SW[0] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheserutttttttteeesueeeemememeeemlseermesesesemhulseerseueueueseeeseersbbbbbbbsemlsmeruhhhhhhhueslsseeeeeeeeeeeeslsehhhhhoeeohhhehe"));
	SW[1] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheeeseeeeeeeeeeeesuhseohhhhhhhhueseeseeeeeeeeeeseseeuhhhhhhhhoeseseeeeeeeeeeeeesesmeeeeemhhhhhhuesseeeeeseeeeeeeesehhhhhoeeohhhhhe"));
	SW[2] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeutsttttstueesueeeeueeeeueeeeseeeeeeemmeeeeeeseeembbbssbbbmeeseeeuhhhhhhhhueesmeeeeeeeeeeeeeesseeeeeeeeeeeeeesehhhhhoeeohhhhhe"));
	SW[3] = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeeeseeeeseeesuhmemeseemesemeseeseseseeseseseseeseseseeseseseseeseseseesesesesmeueseueeseueuheseeeseeeeseeeeesehhhhhoeeohhhhhe"));
	SW[4] = temp;
	//NSE
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesuhhhhhhhhhhhhoeuseeeeeeeeeeeeeeeseeohhhhhhhhoeeeseeeeeesseeeeeeeseohhhhhhhhhhhhmseeeeeeeeeeeeeesehhhhhoeeohhhhhe"));
	NSE[0] = temp;
	temp.redefine(std::string("ehehhhoeeohhhhheelseeeeeeeeeeeeselsemeeeeeemeeeuelueuhhhhhhueeeeeleeeeesseeeeoeeelmemhhhhhhmeeeeelseueeeeeeueeemelseeeeeeeeeeeesehehhhoeeohhhhhe"));
	NSE[1] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhhestttttseeeeeeeesseeeeeuhhhhhhmeuseeeeeeeeuheeseesembmeeeeeeutueeseseehmeeeeeeeeeseuhhhhhhoeeeeemseeeeeeeesbbbbbsehhhhhoeeueeeeee"));
	NSE[2] = temp;
	temp.redefine(std::string("eeeeeeoeeohehhheeeeeeseeeeeteeesehhhhueeeeemeeeuseeeeeeeeeeseeeeehhoeoeohhhehoeeseeeeeeeeeeseeeeehhhhmeeeeeueeemeeeeeseeeeeteeeseeeeeeoeeohhhhhe"));
	NSE[3] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesseeeeeeeeeeeeeeuseoloeeeeeeoloeesebeteeooeebeteeseoroeeeeeeoroeeseeeeeeeeeeeeeemseeeeeeeeeeeeeesehhhhhoeeohhhhhe"));
	NSE[4] = temp;
	//NSW
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesueohhhhhhhhhhhhueeeeeeeeeeeeeeeseeeohhhhhhhhoeeseeeeeeesseeeeeesmhhhhhhhhhhhhoesseeeeeeeeeeeeeesehhhhhoeeohhhhhe"));
	NSW[0] = temp;
	temp.redefine(std::string("ehhhhhoeeohhheheseeeeeeeeeeeesreueeemeeeeeemesreeeeeuhhhhhhueureeeoeeeesseeeeereeeeemhhhhhhmemremeeeueeeeeeuesreseeeeeeeeeeeesreehhhhhoeeohhhehe"));
	NSW[1] = temp;
	temp.redefine(std::string("ehhhhhoeeoeeeeeeseeeeeeeestttttsuemhhhhhhueeeeeseeseehueeeeeeeeseeutueeeeeembmeseeeeeeeeemheesesmeeeeeohhhhhhuessbbbbbseeeeeeeeseeeeeeueeohhhhhe"));
	NSW[2] = temp;
	temp.redefine(std::string("ehhhehoeeoeeeeeeseeeteeeeeseeeeeueeemeeeeeuhhhheeeeeseeeeeeeeeeseeohehhhoeoeohheeeeeseeeeeeeeeesmeeeueeeeemhhhheseeeteeeeeseeeeeehhhhhoeeoeeeeee"));
	NSW[3] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesueeeeeeeeeeeeeeseeoroeeeeeeoroeseetebeeooeetebeseeoloeeeeeeoloesmeeeeeeeeeeeeeesseeeeeeeeeeeeeesehhhhhoeeohhhhhe"));
	NSW[4] = temp;
	//NSEW
	temp.redefine(std::string("ehhehhoeeohhhhheseeseeeeeeeeeeesueeuhhhhhhhhemhueeeeseeeeseeeseeeemeulmlrurmeueeeeseeeseeeeseeeemhueohhhhhhhmeemseeeeeeeeeeeseesehhhhhoeeohhhhhe"));
	NSEW[0] = temp;
	temp.redefine(std::string("ehhhhhoeeoeeeeeeseeeeeeeeetueeeeuobeeeohobeetueueueobeetuembeeteeetuembeetuembeeebeetuembeetuhmemembeetuhoeeeeumeeeembeeeeeeeeeseeeeeeoeeohhhhhe"));
	NSEW[1] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesuemeeeeeeeeeemeueeshhhhhhhhhhseeeeuttutuututtueeeeeeeeeeeeeeeeeemeeeeeeeeeeeeeemseebbbeeeebbbeesehheeeoeeoeeehhe"));
	NSEW[2] = temp;
	temp.redefine(std::string("ehhhhhoeeohhhhheseeeeeeeeeeeeeesueeemeeeeeemeeeueeememeeeememeeeeeoeeehhhheeeoeeeeeueueeeeueueeemeeeueeeeeeueeemseeeeeemmeeeeeesehhhhhheehhhhhhe"));
	ending = temp;
	temp.redefine(std::string("ehhhhhhhhhhhhhheseeeeeeeeeeeeeesueeeeeeeeeeeeeeueeemeeeeeeeemeeeeeeseeeeeeeeseeeeeeseeeeeeeeseeemeeohhhhhhhhoeemseeeeeeeeeeeeeesehhhhhoeeohhhhhe"));
	starting = temp;
	
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
