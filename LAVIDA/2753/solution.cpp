#include <stdio.h>

int c[15][15];

int dr[] = { 0, 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0, 0 };

int main() {

	//             0   1    2    3    4    5    6    7
	int col[8] = { 0, 'R', 'G', 'Y', 'B', 'M', 'C', 'W' };

	int n = 10;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char x;
			scanf(" %c", &x);
			if (x == 'G')c[i][j] = 1;
			else if (x == 'B')c[i][j] = 2;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = 0;
			for (int k = 0; k < 5; k++) {
				int ni = i + dr[k], nj = j + dc[k];
				if (ni < 0 || nj < 0 || ni >= n || nj >= n)continue;
				x |= (1 << (c[ni][nj]));
			}
			if (j)printf(" ");
			printf("%c", col[x]);
		}printf("\n");
	}

}