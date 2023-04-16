#pragma once
#include <stdio.h>
#include <easyx.h>

#define MaxChess 19           //���̸���

extern int map[MaxChess][MaxChess];  //����
extern int flag;                     //��ǰ�غ���

//---service---//
void init();//��ʼ��
int isWin(int x, int y);
int playerMove(int x, int y);

//---view---//
void menuView();
void gameView_ShowMap();
void winView();
void gameView();
void button(int x, int y, int w, int h, const char* text);
