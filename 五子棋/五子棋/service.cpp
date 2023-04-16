#include "function.h"

void init() {
	for (int i = 0; i < MaxChess; i++)
		for (int j = 0; j < MaxChess; j++)
			map[i][j] = 0;
}

int isWin(int x, int y) {
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

	int i, j;
	for (i = 0; i < 5 ; i++) {
		cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
		for (j = 0; j < 4 ; j++) {
			if (map[x - i + j][y] == map[x - i + j + 1][y])
				cnt1++;
			if (map[x][y - i + j] == map[x][y - i + j + 1])
				cnt2++;
			if (map[x - i + j][y - i + j] == map[x - i + j + 1][y - i + j + 1])
				cnt3++;
			if (map[x - i + j][y + i - j] == map[x - i + j + 1][y + i - j - 1])
				cnt4++;
		}
		if (cnt1 == 4 || cnt2 == 4 || cnt3 == 4 || cnt4 == 4)
			return 1;
	}
	return 0;
}

int playerMove(int x, int y) {
	setbkmode(TRANSPARENT);
	if (!map[x][y]) {
		switch (flag % 2) {
		case 0:
			map[x][y] = 1;
			setfillcolor(BLACK);
			solidcircle(y * 30 + 50, x * 30 + 50, 10);
			break;
		case 1:
			map[x][y] = 2;
			setfillcolor(WHITE);
			solidcircle(y * 30 + 50, x * 30 + 50, 10);
			break;
		}
		return 1;
	}
	return 0;
}