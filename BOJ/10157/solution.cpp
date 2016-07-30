#include <stdio.h>
#include <memory.h>

int rom[1003][1003];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int main() {

	int c, r, k;
	while (scanf("%d %d %d", &c, &r, &k) == 3) {

		if (r*c < k)printf("0\n");
		else {

			memset(rom, 0xff, sizeof(rom));

			for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++)rom[i][j] = 0;

			int x = r, y = 1;

			rom[x][y] = 1;

			int v = 1, d = 0;

			while (v < k) {

				int nx = x + dr[d], ny = y + dc[d];

				if (rom[nx][ny]) {

					d++;
					d %= 4;

				}
				else {

					rom[nx][ny] = ++v;
					x = nx, y = ny;

				}

			}

			printf("%d %d\n", y, 1 + r - x);

		}

	}

}