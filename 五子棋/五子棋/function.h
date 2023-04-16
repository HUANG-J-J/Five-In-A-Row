#pragma once
#include <stdio.h>
#include <easyx.h>

#define MaxChess 19           //棋盘格数

extern int map[MaxChess][MaxChess];  //棋盘
extern int flag;                     //当前回合数

//---service---//
void init();//初始化
int isWin(int x, int y);
int playerMove(int x, int y);

//---view---//
void menuView();
void gameView_ShowMap();
void winView();
void gameView();
void button(int x, int y, int w, int h, const char* text);
