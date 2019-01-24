#pragma once
class pos
{
public:
	int x;
	int y;
	pos() = default;//careful
	pos operator + (pos const &obj);
	pos(int x1,int y1);
	pos operator * (int i);
	bool const operator == (pos const &obj);
};

