#include <stdio.h>
#include <memory.h>

bool chk[102][102];
int e[102][102];
int n;

void dfs(int x, int y, int h) {
	if (x > n || y > n || x < 1 || y < 1)return;
	if (chk[x][y] == true)return;


	if (e[x][y] <= h)return;

	chk[x][y] = true;

	dfs(x + 1, y, h);
	dfs(x - 1, y, h);
	dfs(x, y + 1, h);
	dfs(x, y - 1, h);

	return;
}
int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &e[i][j]);

	int ans = 0;
	for (int h = 0; h <= 100; h++) {

		memset(chk, 0, sizeof(chk));

		int s = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (chk[i][j] == false && e[i][j] > h) {
					s++;
					dfs(i, j, h);
				}
			}
		}

		if (ans < s) ans = s;

	}

	printf("%d\n", ans);
}