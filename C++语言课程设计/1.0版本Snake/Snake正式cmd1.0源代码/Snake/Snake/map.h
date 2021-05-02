#pragma once
#ifndef MAP_H
#define MAP_H
#include "all_head.h"
//-----------//
const int mapsize = 34;
const int rate = 15;
//0��ʾ�հף�1�ߵ����壬2�ߵ�ͷ����3���ӣ�4�ɴݻ�ǽ��5���ɴݻ�ǽ
extern COLORREF snakebody[rate][rate];
extern COLORREF snakehead[rate][rate];
extern COLORREF bean[rate][rate];
extern COLORREF wall_distructible[rate][rate];
extern COLORREF wall_indistrutible[rate][rate];
extern COLORREF black[rate][rate];

class Map {
public:
	int mapp[mapsize][mapsize];
	void show();
};

extern Map map[3];
extern pos p_next, p_head, p_tail;

///////////////////����////////////////////////
void delay(int t);
void Print_snake(pos p_next, pos p_head);
void Print_snake(pos p_next, pos p_head, pos p_tail);
void Judge(Snake &snake);
void pause();

struct Rank {
	string name;
	int score = 0;
	int time = 0;
};

void SignInRank();
#endif
