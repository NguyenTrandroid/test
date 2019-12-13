#include "foods.h"


int foods::getX() {
	return x;
}
int foods::getY() {
	return y;
}
bool foods::check_point_random(List l, int x, int y) {
	for (Point *p = l.pHead; p != NULL; p = p->pNext) {
		if (p->x == x && p->y == y) {
			return true;
		}
	}
	return false;
}
void foods::point_random(List &l) {
	int xx;
	int yy;
	while (true)
	{
		srand(time(NULL));
		xx = 15 + 1 + rand() % (39 - 15 - 1);
		yy = 5 + 1 + rand() % (15 - 5 - 1);

		if (xx != y && yy != y && !check_point_random(l, xx, yy)) {
			break;
		}
	}
	gotoXY(x, y);
	cout << " ";
	x = xx;
	y = yy;
	gotoXY(x, y);
	SetColor(15);
	cout << "$";
}
bool foods::check_coordinate_point(List & l, int & score)
{

	if (l.pHead->x == x && l.pHead->y == y) {
		score += 5;
		gotoXY(17, 2);
		cout << setw(50) << " ";
		gotoXY(17, 2);
		SetColor(15);
		cout << "Diem: " << score;
		return true;
	}
	else {
		return false;
	}
}


foods::foods()
{
}
foods::~foods()
{
}
