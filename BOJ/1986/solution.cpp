#include <stdio.h>

int chk[1001][1001];

class ele {
public:
	int x, y;
}Q[101], N[101], P[101];

int main()
{
	int R, C;
	scanf("%d %d", &R, &C);

	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d %d", &Q[i].x, &Q[i].y);
		chk[Q[i].x][Q[i].y] = 1;
	}

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &N[i].x, &N[i].y);
		chk[N[i].x][N[i].y] = 2;
	}

	int p;
	scanf("%d", &p);
	for (int i = 1; i <= p; i++) {
		scanf("%d %d", &P[i].x, &P[i].y);
		chk[P[i].x][P[i].y] = 3;
	}

	for (int j = 1; j <= q; j++) {
		int x = Q[j].x, y = Q[j].y;
		for (int i = x - 1; i >= 1; i--) {
			if (chk[i][y] == 0)chk[i][y] = 4;
			else if (chk[i][y] == 4)continue;
			else
				break;
		}
		for (int i = x + 1; i <= R; i++) {
			if (chk[i][y] == 0)chk[i][y] = 4;
			else if (chk[i][y] == 4)continue;
			else
				break;
		}
		for (int i = y + 1; i <= C; i++) {
			if (chk[x][i] == 0)chk[x][i] = 4;
			else if (chk[x][i] == 4)continue;
			else
				break;
		}
		for (int i = y - 1; i >= 1; i--) {
			if (chk[x][i] == 0)chk[x][i] = 4;
			else if (chk[x][i] == 4)continue;
			else
				break;
		}
		for (int i = x - 1; i >= 1; i--) {
			if (y - (x - i) < 1)break;
			if (chk[i][y - (x - i)] == 0)chk[i][y - (x - i)] = 4;
			else if (chk[i][y - (x - i)] == 4)continue;
			else
				break;
		}
		for (int i = x + 1; i <= R; i++) {
			if (y - (i - x) < 1)break;
			if (chk[i][y - (i - x)] == 0)chk[i][y - (i - x)] = 4;
			else if (chk[i][y - (i - x)] == 4)continue;
			else
				break;
		}
		for (int i = x - 1; i >= 1; i--) {
			if (y + (x - i) > C)break;
			if (chk[i][y + (x - i)] == 0)chk[i][y + (x - i)] = 4;
			else if (chk[i][y + (x - i)] == 4)continue;
			else
				break;
		}
		for (int i = x + 1; i <= R; i++) {
			if (y + (i - x) > C)break;
			if (chk[i][y + (i - x)] == 0)chk[i][y + (i - x)] = 4;
			else if (chk[i][y + (i - x)] == 4)continue;
			else
				break;
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = N[i].x, y = N[i].y;
		if (x > 2) {
			if (y > 1 && chk[x - 2][y - 1] == 0)chk[x - 2][y - 1] = 4;
			if (y < C && chk[x - 2][y + 1] == 0)chk[x - 2][y + 1] = 4;
		}
		if (x < R - 1) {
			if (y > 1 && chk[x + 2][y - 1] == 0)chk[x + 2][y - 1] = 4;
			if (y < C && chk[x + 2][y + 1] == 0)chk[x + 2][y + 1] = 4;
		}
		if (x > 1) {
			if (y > 2 && chk[x - 1][y - 2] == 0)chk[x - 1][y - 2] = 4;
			if (y < C - 1 && chk[x - 1][y + 2] == 0)chk[x - 1][y + 2] = 4;
		}
		if (x < R) {
			if (y > 2 && chk[x + 1][y - 2] == 0)chk[x + 1][y - 2] = 4;
			if (y < C - 1 && chk[x + 1][y + 2] == 0)chk[x + 1][y + 2] = 4;
		}
	}

	int ans = 0;
	for (int i = 1; i <= R; i++)for (int j = 1; j <= C; j++)if (!chk[i][j])ans++;

	printf("%d\n", ans);
}