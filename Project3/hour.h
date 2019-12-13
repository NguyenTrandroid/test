#pragma once
#include <iostream>
#include <conio.h>
#include<Windows.h>
struct Hour {
	int hour;
	int minute;
	int second;
};
char inToA(int k);
void insertarray(char *h, Hour *j);
bool changetime(Hour *h);
void WriteBlockChar(char * Arraych,
	int row, int col,
	int x, int y,
	int color);
void printClock(Hour *h);