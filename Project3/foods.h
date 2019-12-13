#pragma once
#include"point.h"
class foods
{
private:
	int x = 0;
	int y = 0;
public:
	int getX();
	int getY();
	bool check_point_random(List l, int x, int y);
	void point_random(List &l);
	bool check_coordinate_point(List &l, int &score);
	foods();
	~foods();
};

