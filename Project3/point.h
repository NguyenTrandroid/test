#pragma once
#include "uilib.h"
#include<stdio.h>
#include <iostream>
#include <conio.h>
#include<random>
#include <iomanip>

using namespace std;
struct point {
	int x;
	int y;
	struct point *pNext;
};
typedef struct point Point;
struct list
{
	int size;
	point *pHead;
	point *pTail;

};
typedef struct list List;
Point *Create_Point(int x, int y);
void Add_Head(List &l, Point *p);
void Add_Tail(List &l, Point *p);
void Delete_Head(List &l);
void init_snake(List &l);
int random(int a, int b);
void show_snake(List l);
void Create_List(List &l);
void deleteList(Point *head);

