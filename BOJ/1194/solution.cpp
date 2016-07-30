#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <queue>

#include <algorithm>

using namespace std;

class ele {
public:
	int r, c, s;
	ele() {}
	ele(int a, int b, int x) { r = a, c = b, s = x; }
};

char str[53][53];

int dp[53][53][1 << 6];


int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int r, c;

int main() {

	scanf("%d %d", &r, &c);

	int x, y;

	for (int i = 0; i < r; i++) {
		scanf("%s", str[i]);
		for (int j = 0; j < c; j++) {

			if (str[i][j] == '0') {
				x = i, y = j;
			}

			for (int k = 0; k < (1 << 6); k++) {
				dp[i][j][k] = INT_MAX;
			}

		}
	}

	queue <ele> q;
	q.emplace(x, y, 0);

	dp[x][y][0] = 0;

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		int i = f.r, j = f.c, s = f.s;

		if (str[i][j] == '1') {
			printf("%d\n", dp[i][j][s]);
			return 0;
		}

		int &cur = dp[i][j][s];

		for (int k = 0; k < 4; k++) {

			int ni = i + dr[k];
			int nj = j + dc[k];

			if (ni < 0 || ni >= r || nj < 0 || nj >= c)continue;

			if (str[ni][nj] == '#')continue;

			if (str[ni][nj] <= 'F' && str[ni][nj] >= 'A') {
				int &ret = dp[ni][nj][s];
				int what = str[ni][nj] - 'A';
				if (s & (1 << what)) {
					if (ret > 1 + cur) {
						ret = 1 + cur;
						q.emplace(ni, nj, s);
					}
				}
			}
			else if (str[ni][nj] <= 'f' && str[ni][nj] >= 'a') {
				// get key
				int gkey = str[ni][nj] - 'a';
				int &ret = dp[ni][nj][s | (1 << gkey)];

				if (ret > 1 + cur) {
					ret = 1 + cur;
					q.emplace(ni, nj, s | (1 << gkey));
				}
			}
			else {
				int &ret = dp[ni][nj][s];
				if (ret > 1 + cur) {
					ret = 1 + cur;
					q.emplace(ni, nj, s);
				}
			}

		}


	}

	printf("-1\n");

}

/*
4 4
0A1A
.A..
aAAA
....
*/