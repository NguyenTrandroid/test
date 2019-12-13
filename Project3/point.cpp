#include "point.h"


Point *Create_Point(int x, int y) {
	Point *p = new Point;
	if (p == NULL)
		return NULL;
	p->x = x;
	p->y = y;
	p->pNext = NULL;
	return p;
}
void Add_Head(List &l, Point *p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
	l.size++;
}
void Add_Tail(List &l, Point *p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;

	}
	l.size++;
}
void Delete_Head(List &l) {
	if (l.pHead == NULL) {
		return;
	}
	Point *p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
	l.size--;
}
void Delete_Tail(List &l) {
	if (l.pHead == NULL)
		return;
	for (Point *p = l.pHead; p != NULL; p = p->pNext) {
		if (p->pNext == l.pTail) {
			delete l.pTail;
			p->pNext = NULL;
			l.pTail = p;
		}
	}
	l.size--;

}
void init_snake(List &l) {
	int x = 15, y = 8;
	while (x > 10)
	{
		Point *p = Create_Point(x, y);
		Add_Tail(l, p);
		x--;
	}
}
int random(int a, int b)
{
	random_device rd;
	mt19937 eng(rd());
	uniform_int_distribution<> distr(a, b);
	return distr(eng);
}
void show_snake(List l) {

	for (Point *p = l.pHead; p != NULL; p = p->pNext) {
		if (p == l.pHead) {
			SetColor(12);
			gotoXY(p->x, p->y);
			cout << (char)233;
		}
		else
		{
			SetColor(random(0, 255));
			gotoXY(p->x, p->y);
			cout << (char)229;
		}
	}

}
void Create_List(List &l) {
	l.size = 0;
	l.pHead = l.pTail = NULL;
}
void deleteList(Point *head) {
	if (head != NULL) {
		deleteList(head->pNext);
		delete head;
	}
}

