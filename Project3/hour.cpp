#include "hour.h"
char inToA(int k) {
	switch (k)
	{
	case 0:return '0';
	case 1:return '1';
	case 2:return '2';
	case 3:return '3';
	case 4:return '4';
	case 5:return '5';
	case 6:return '6';
	case 7:return '7';
	case 8:return '8';
	case 9:return '9';
	default:
		break;
	}
}
void insertarray(char *h, Hour *j) {
	int bait = 0;
	bait = j->second;
	h[7] = inToA(bait % 10);
	h[6] = inToA(bait /= 10);

	bait = j->minute;
	h[4] = inToA(bait % 10);
	h[3] = inToA(bait /= 10);

	bait = j->hour;
	h[1] = inToA(bait % 10);
	h[0] = inToA(bait /= 10);

}
bool changetime(Hour *h) {
	if (h->second > 0) --h->second;
	else if (h->minute > 0) {
		h->second = 59;
		--h->minute;
	}
	else if (h->hour > 0)
	{
		--h->hour;
		h->minute = 59;
		h->second = 59;
	}
	else return 0;
	return 1;
}
void WriteBlockChar(char * Arraych,int row, int col,int x, int y,int color)
{
	CHAR_INFO *charater = new CHAR_INFO[row*col];
	for (int i = 0; i < row*col; i++) {
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = { col,row };
	COORD pos = { 0,0 };
	SMALL_RECT earea = { x,y,x + col - 1,y + row - 1 };
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}
static void printClock(Hour *h,bool &stop) {
	char a[8] = { '0','0',':','0','0',':','0','0' };
	while (stop)
	{
		if (!changetime(h)) stop = 0;
		insertarray(a, h);
		WriteBlockChar(a, 1, 8, 22, 4, 0x004);
		Sleep(1000);
	}
	stop = 0;
	return;
}