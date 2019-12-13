#include "hander.h";
#include "foods.h"

bool game_over(List &l,bool &stop) {
	if (stop == 0) {
		return true;
	}
	else {
		for (Point *p = l.pHead->pNext; p != NULL; p = p->pNext) {
			if (p->x == l.pHead->x && p->y == l.pHead->y) {
				return true;
			}
		}
	}
	return false;
}
int game_over(int score, int *a, int total) {
		SetBGColor(19);
		gotoXY(8, 7); for (int i = 0; i < 26; i++) cout << " ";
		gotoXY(8, 8); for (int i = 0; i < 26; i++) cout << " ";
		gotoXY(8, 9); for (int i = 0; i < 26; i++) cout << " ";
		gotoXY(8, 10); for (int i = 0; i < 26; i++) cout << " ";
		gotoXY(8, 11); for (int i = 0; i < 26; i++) cout << " ";
		gotoXY(8, 12); for (int i = 0; i < 26; i++) cout << " ";
		gotoXY(8, 13); for (int i = 0; i < 26; i++) cout << " ";
		SetColor(15);
		gotoXY(17, 7);
		cout << "Game over";
		SetColor(0);
	/*	if (check_highScore(a, 450, total)!=-1) {
		gotoXY(17, 9);
		cout << "Diem cao";
		}
		else {
		gotoXY(18, 9);
		cout << "Diem so";
		}*/
		gotoXY(21, 10);
		cout << score;
		gotoXY(18, 12);
		cout << "Choi lai";
		gotoXY(18, 13);
		cout << "Thoat";
		gotoXY(16, 12);
		cout << (char)254;
		int flag = 0;
		while (true)
		{
			if (_kbhit()) {
				char c = _getch();
				if (c == 's' || c == 'w') {
					if (flag == 0)
					{
						gotoXY(16, 12);
						cout << "  ";
						gotoXY(16, 13);
						cout << (char)254;
						flag = 1;
					}
					else {
						gotoXY(16, 13);
						cout << "  ";
						gotoXY(16, 12);
						cout << (char)254;
						flag = 0;
					}
				}
				if (c == '\r') {
					break;
				}
			}
		}
		return flag;
	
	}
void direction(List &l, int direction, int numberPoint) {

	if (direction == RIGHT) {

		int xRight = l.pHead->x;
		int yRight = l.pHead->y;
		gotoXY(l.pHead->x, l.pHead->y);
		cout << " ";
		Delete_Head(l);
		int xRight1 = l.pHead->x;
		int yRight1 = l.pHead->y;
		for (Point *p = l.pHead; p != NULL; p = p->pNext) {
			if (p == l.pHead) {
				gotoXY(p->x, p->y);
				cout << " ";
				l.pHead->x = xRight;
				l.pHead->y = yRight;
			}
			else {
				gotoXY(p->x, p->y);
				cout << " ";
				int xRight2 = p->x;
				int yRight2 = p->y;
				p->x = xRight1;
				p->y = yRight1;
				xRight1 = xRight2;
				yRight1 = yRight2;
			}
		}
		Point * pRight = Create_Point(xRight + 1, yRight);
		Add_Head(l, pRight);


	}
	else if (direction == DOWN) {
		int xDown = l.pHead->x;
		int yDown = l.pHead->y;
		gotoXY(l.pHead->x, l.pHead->y);
		cout << " ";
		Delete_Head(l);
		int xDown1 = l.pHead->x;
		int yDown1 = l.pHead->y;
		for (Point *p = l.pHead; p != NULL; p = p->pNext) {
			if (p == l.pHead) {
				gotoXY(p->x, p->y);
				cout << " ";
				l.pHead->x = xDown;
				l.pHead->y = yDown;
			}
			else {
				gotoXY(p->x, p->y);
				cout << " ";
				int xDown2 = p->x;
				int yDown2 = p->y;
				p->x = xDown1;
				p->y = yDown1;
				xDown1 = xDown2;
				yDown1 = yDown2;
			}
		}
		Point * pDown = Create_Point(xDown, yDown + 1);
		Add_Head(l, pDown);
	}
	else if (direction == LEFT) {
		int xLeft = l.pHead->x;
		int yLeft = l.pHead->y;
		gotoXY(l.pHead->x, l.pHead->y);
		cout << " ";
		Delete_Head(l);
		int xLeft1 = l.pHead->x;
		int yLeft1 = l.pHead->y;
		for (Point *p = l.pHead; p != NULL; p = p->pNext) {
			if (p == l.pHead) {
				gotoXY(p->x, p->y);
				cout << " ";
				l.pHead->x = xLeft;
				l.pHead->y = yLeft;
			}
			else {
				gotoXY(p->x, p->y);
				cout << " ";
				int xLeft2 = p->x;
				int yLeft2 = p->y;
				p->x = xLeft1;
				p->y = yLeft1;
				xLeft1 = xLeft2;
				yLeft1 = yLeft2;
			}
		}
		Point * pLeft = Create_Point(xLeft - 1, yLeft);
		Add_Head(l, pLeft);

	}
	else if (direction == UP) {
		int xUp = l.pHead->x;
		int yUp = l.pHead->y;
		gotoXY(l.pHead->x, l.pHead->y);
		cout << " ";
		Delete_Head(l);
		int xUp1 = l.pHead->x;
		int yUp1 = l.pHead->y;
		for (Point *p = l.pHead; p != NULL; p = p->pNext) {
			if (p == l.pHead) {
				gotoXY(p->x, p->y);
				cout << " ";
				l.pHead->x = xUp;
				l.pHead->y = yUp;
			}
			else {
				gotoXY(p->x, p->y);
				cout << " ";
				int xUp2 = p->x;
				int yUp2 = p->y;
				p->x = xUp1;
				p->y = yUp1;
				xUp1 = xUp2;
				yUp1 = yUp2;
			}
		}
		Point * pUp = Create_Point(xUp, yUp - 1);
		Add_Head(l, pUp);

	}
}
int startgame(List &l, int &score,bool &stop,thread &clock) {
	system("cls");
	Hour hh = { 00,01,00 };
	Hour *h = &hh;
	stop = 1;
	clock = thread(printClock, h,stop);
	draw_frames();
	gotoXY(17, 2);
	cout << "Diem: " << score;
	gotoXY(11, 4);
	SetColor(12);
	cout << "Thoi gian: ";
	int keyInput = RIGHT;
	foods f;
	f.point_random(l);
	while (l.pHead->x < 39 && l.pHead->y < 15 && l.pHead->y>5 && l.pHead->x>2)
	{
		direction(l, keyInput, l.size);
		show_snake(l);
		if (f.check_coordinate_point(l,score)) {
			Point * p = Create_Point(0, 0);
			Add_Tail(l, p);
			f.point_random(l);					
		}
		if (game_over(l,stop)) {
			deleteList(l.pHead);
			break;

		}
		Sleep(150);
		if (_kbhit()) {
			char c = _getch();
			if (c == 's') {
				if (keyInput != UP)
					keyInput = DOWN;
			}
			else if (c == 'd') {
				if (keyInput != LEFT)
					keyInput = RIGHT;
			}
			else if (c == 'a') {
				if (keyInput != RIGHT)
					keyInput = LEFT;
			}
			else if (c == 'w') {
				if (keyInput != DOWN)
					keyInput = UP;
			}
		}
	}
	stop = 0;
	clock.join();
	return 0;
}
int Menu(List &l, int &score, int *a, int total,bool &stop, thread &clock) {
		SetColor(15);
		for (int i = 20; i < 50; i++) {
			gotoXY(i, 2);
			cout << (char)220;
		}
		for (int i = 20; i <= 49; i++) {
			gotoXY(i, 10);
			cout << (char)223;
		}
		for (int i = 3; i <= 9; i++) {
			gotoXY(20, i);
			cout << (char)221;
		}
		for (int i = 3; i <= 9; i++) {
			gotoXY(49, i);
			cout << (char)222;
	
		}
		gotoXY(30, 3);
		cout << "Huong dan";
		gotoXY(21, 5);
		cout << "Dieu khien: W A S D";
		gotoXY(21, 6);
		cout << "Luat choi : ";
		gotoXY(22, 7);
		cout << "- Di chuyen ran an cuc moi";
		gotoXY(22, 8);
		cout << "- Ran cham tuong => thua";
		gotoXY(22, 9);
		cout << "- Ran tu can duoi => thua";
		gotoXY(30, 12);
		cout << "Bat dau";
		gotoXY(30, 13);
		cout << "Diem cao";
		gotoXY(27, 12);
		cout << (char)254;
		int flag = 0;
		while (true)
		{
			if (_kbhit()) {
				char c = _getch();
				if (c == 's' || c == 'w') {
					if (flag == 0)
					{
						gotoXY(27, 12);
						cout << "  ";
						gotoXY(27, 13);
						cout << (char)254;
						flag = 1;
					}
					else {
						gotoXY(27, 13);
						cout << "  ";
						gotoXY(27, 12);
						cout << (char)254;
						flag = 0;
					}
	
				}
				if (c == '\r') {
					break;
				}
			}
		}
		if (flag == 0) {
			Create_List(l);
			init_snake(l);
			score = 0;
			int a = startgame(l, score,stop, clock);
			return 0;
		}
		else
		{
		/*	system("cls");
			for (int i = 0; i < total; i++) {
				cout << a[i] << endl;
			}
			_getch();*/
			return 1;
		
		}
	}