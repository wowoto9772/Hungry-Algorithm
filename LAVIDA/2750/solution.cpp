#include <stdio.h>

int a[8][8];
int b[8][8];
int c[8][8];
int e[8][8];

int n = 5;

int dr[] = { 0, 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0, 0 };

void fuck(int i, int j) {

	if (j == n + 1) {
		if (i != n) {
			fuck(i + 1, 1);
		}
		else {
			if (c[n][n] == a[n][n]) {
				for (int x = 1; x <= n; x++)for (int y = 1; y <= n; y++)e[x][y] = b[x][y];
			}
		}
		return;
	}

	if (c[i][j] > a[i][j]) {
		return;
	}
	else if (c[i][j] == a[i][j]) {
		fuck(i, j + 1);
	}
	else {

		int rem = a[i][j] / c[i][j];

		for (int x = 1; x <= rem; x <<= 1) {

			if (i > 1) {
				if (c[i - 1][j] * x != a[i - 1][j])continue;
			}

			if (j > 1) {
				if (c[i][j - 1] * x > a[i][j - 1])continue;
				if (i == n && c[i][j - 1] * x != a[i][j - 1])continue;
			}

			if (i < n && c[i + 1][j] * x > a[i + 1][j])continue;
			if (j < n && c[i][j + 1] * x > a[i][j + 1])continue;

			if (b[i][j] * x > e[i][j])continue;

			if (i > 1)c[i - 1][j] *= x;
			if (j > 1)c[i][j - 1] *= x;
			if (j < n)c[i][j + 1] *= x;
			if (i < n)c[i + 1][j] *= x;

			c[i][j] *= x;
			b[i][j] *= x;
			fuck(i, j + 1);
			b[i][j] /= x;
			c[i][j] /= x;

			if (i > 1)c[i - 1][j] /= x;
			if (j > 1)c[i][j - 1] /= x;
			if (j < n)c[i][j + 1] /= x;
			if (i < n)c[i + 1][j] /= x;
		}
	}
}

int main() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			b[i][j] = c[i][j] = 1;
			e[i][j] = 1024;
		}
	}

	fuck(1, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j > 1)printf(" ");
			printf("%d", e[i][j]);
		}printf("\n");
	}

}

/*

1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1


in
1 4 32 8 4
4 32 16 16 1
32 16 16 2 2
8 16 2 8 16
4 1 2 16 16

out
1 1 2 4 1
1 2 4 1 1
2 4 1 1 1
4 1 1 2 2
1 1 1 2 4

in
1 1 1 1 2
1 1 4 4 8
1 4 8 256 128
1 1 32 1024 2048
1 1 8 512 512


out
1 1 1 1 1
1 1 1 1 2
1 1 4 2 4
1 1 1 8 8
1 1 1 8 8

*/