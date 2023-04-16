#include "function.h"

void menuView() {
	initgraph(1070, 543);
	IMAGE img;
	loadimage(&img, "../picture/sucai.png");
	putimage(0, 0, &img);

	ExMessage msg;
	for (;;) {
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
				case WM_LBUTTONDOWN:
					if (msg.x >= 350 && msg.x <= 350 + 150 && msg.y >= 400 && msg.y <= 400 + 45) {
						exit(0);
					} else if (msg.x >= 555 && msg.x <= 555 + 150 && msg.y >= 400 && msg.y <= 400 + 45) {
						closegraph();
						gameView();
					}
					break;
				default:
					break;
			}
		}
	}
}

void gameView_ShowMap() {
	setbkcolor(RGB(203, 200, 157));
	cleardevice();
	setfillcolor(RGB(196, 134, 77));
	solidroundrect(25, 25, 615, 615, 10, 10);
	setlinestyle(PS_SOLID, 3);
	setlinecolor(RGB(104, 57, 20));

	int x = 50, y = 50;
	for (int i = 0; i < MaxChess; i++) {
		line(50, y, 590, y);
		line(x, 50, x, 590);
		x += 30;
		y += 30;
	}

	settextstyle(40, 0, "华文隶书");
	settextcolor(RGB(100, 50, 20));
	button(650, 550, 150, 50, "认输");
	settextstyle(70, 0, "华文隶书");
	outtextxy(690, 100, "五");
	outtextxy(690, 200, "子");
	outtextxy(690, 300, "棋");
}

void winView() {
	initgraph(1070, 543);
	IMAGE img1, img2;
	loadimage(&img1, "../picture/win1.jpg");
	loadimage(&img2, "../picture/win2.jpg");
	if (flag % 2 == 0) {
		putimage(0, 0, &img1);
	} else if (flag % 2 == 1) {
		putimage(0, 0, &img2);
	}
	ExMessage msg;
	for (;;) {
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
				case WM_LBUTTONDOWN:
					closegraph;
					menuView();
					break;
				default:
					break;
			}
		}
	}
}

void gameView() {
	init();
	initgraph(850, 650);
	gameView_ShowMap();
	int i = 0, j = 0;
	ExMessage msg;
	for (;;) {
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
				case WM_LBUTTONDOWN:
					if (msg.x >= 50 && msg.x <= 590 && msg.y >= 50 && msg.y <= 590) {
						i = (msg.y - 35) / 30;
						j = (msg.x - 35) / 30;
						if (!playerMove(i, j))
							break;
						if (isWin(i, j)) {
							closegraph();
							winView();
						}
						flag++;
					} else if (msg.x >= 650 && msg.x <= 800 && msg.y >= 550 && msg.y <= 600) {
						flag++;
						winView();
					}
					break;
				default:
					break;
			}
		}
	}
}

void button(int x, int y, int w, int h, const char *text) {
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(165, 114, 71));
	fillroundrect(x, y, x + w, y + h, 10, 10);
	char text_[50] = "bubu";
	strcpy_s(text_, text);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;

	outtextxy(tx, ty, text);
}