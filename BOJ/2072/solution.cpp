#include <stdio.h>

int X[20][20];
int c = 0, f;

void Algo(int i, int j, int di, int dj) {
	if (i < 1 || j < 1 || i>19 || j>19)return;
	if (X[i][j] == f) {
		c++;
		Algo(i + di, j + dj, di, dj);
	}
	return;
}

int main() {
	int n;
	scanf("%d", &n);

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (ans)continue;

		X[a][b] = i % 2 + 1;
		f = i % 2 + 1;

		c = -1;
		Algo(a, b, 1, 0);
		Algo(a, b, -1, 0);

		if (c == 5) {
			ans = i;
			continue;
		}

		c = -1;
		Algo(a, b, 0, 1);
		Algo(a, b, 0, -1);

		if (c == 5) {
			ans = i;
			continue;
		}

		c = -1;
		Algo(a, b, 1, 1);
		Algo(a, b, -1, -1);

		if (c == 5) {
			ans = i;
			continue;
		}

		c = -1;
		Algo(a, b, 1, -1);
		Algo(a, b, -1, +1);

		if (c == 5) {
			ans = i;
			continue;
		}

	}

	if (ans)printf("%d\n", ans);
	else
		printf("-1\n");
}