#pragma once
#include "point.h"
#include "ui.h"
#include <thread>
#include "hour.h"


int Menu(List &l, int &score, int *a, int total, bool &stop, thread &clock);
int startgame(List &l, int &score, bool &stop, thread &clock);
void save_high_score(int *a, int &total, int score);
int game_over(int score, int *a, int total);
int check_highScore(int *a, int total, int score);
bool game_over(List &l, bool &stop);
int game_over(int score, int *a, int total);
void direction(List &l, int direction, int numberPoint);


