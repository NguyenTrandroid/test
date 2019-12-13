#include <ios>
#include<stdlib.h>
#include<time.h>
#include <thread>
#include <dos.h> 
#include <windows.h>
#include <ctime>
#include <string>
#include <future>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "hander.h"
using namespace std;
bool stop = 1;
int main() {
	setDefaultConfig();
	ShowCur(false);
	List l;
	int score;
	int totalscore = 0;
	int *top = new int[10];
	thread clock;
	int a = Menu(l, score, top, totalscore,stop,clock);
	while (true)
	{
		if (a == 0) {
			if (game_over(score, top, totalscore) == 0) {
			//	save_high_score(top, totalscore, score);
				cout << totalscore;
				SetBGColor(0);
				system("cls");
				a = Menu(l, score, top, totalscore,stop,clock);
			}
			else {
				break;
			}
		}
		else {
			SetBGColor(0);
			system("cls");
			a = Menu(l, score, top, totalscore,stop,clock);
		}
	}
	_getch();
	return 0;
}

