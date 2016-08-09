#include <stdio.h>
#include <vector>

using namespace std;

char str[8][8];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

bool chk[1 << 25];

int ans = 0;

#define node(i, j) (i*5+j)

void dfs(int S, int c, int s) {

	if (c == 7) {
		if (!chk[S] && s >= 4) {
			chk[S] = true;
			ans++;
		}
		return;
	}
	else {

		for (int i = 0; i < 25; i++) {

			if (S&(1 << i)) { // cur x, y

				int x = i / 5, y = i % 5;

				for (int j = 0; j < 4; j++) {

					// nxy x, y

					int nx = x + dr[j], ny = y + dc[j];

					if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)continue;

					int z = node(nx, ny);

					if (S&(1 << z))continue;

					int add = 0;

					if (str[nx][ny] == 'S')add++;

					dfs(S | (1 << z), c + 1, s + add);

				}

			}

		}

	}

}

int main() {

	int n = 5;
	for (int i = 0; i < n; i++)scanf("%s", str[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c = str[i][j];
			dfs(1 << node(i, j), 1, c == 'S');
		}
	}

	printf("%d\n", ans);

}

/*
SYSYS
YYYYY
YYYYS
YYYYY
YYYYY

*/