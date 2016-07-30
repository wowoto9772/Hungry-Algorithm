#include <stdio.h>

int brd[5][5];

int main() {

	int p;
	scanf("%d", &p);

	p--;

	int win = 0;

	for (int i = 1; i <= 3; i++)for (int j = 1; j <= 3; j++)brd[i][j] = -1;

	for (int i = 1; i <= 9; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (win)continue;

		brd[a][b] = p;
		p = !p;

		for (int j = 1; j <= 3 && !win; j++) {
			if (brd[1][j] != -1) {
				if (brd[1][j] == brd[2][j] && brd[2][j] == brd[3][j]) {
					win = brd[1][j] + 1;
				}
			}
			if (brd[j][1] != -1) {
				if (brd[j][1] == brd[j][2] && brd[j][2] == brd[j][3]) {
					win = brd[j][1] + 1;
				}
			}
		}

		if (brd[1][1] != -1 && brd[1][1] == brd[2][2] && brd[2][2] == brd[3][3])win = brd[1][1] + 1;
		if (brd[1][3] != -1 && brd[1][3] == brd[2][2] && brd[2][2] == brd[3][1])win = brd[1][3] + 1;

	}

	printf("%d\n", win);

}