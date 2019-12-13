#include "ui.h"
#include<stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;
void draw_frames() {
	for (int i = 2; i < 40; i++) {
		gotoXY(i, 5);
		cout << (char)220;
	}
	for (int i = 2; i <= 39; i++) {
		gotoXY(i, 15);
		cout << (char)223;
	}
	for (int i = 6; i <= 14; i++) {
		gotoXY(2, i);
		cout << (char)221;
	}
	for (int i = 6; i <= 14; i++) {
		gotoXY(39, i);
		cout << (char)222;

	}
}