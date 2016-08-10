#include <stdio.h>

#include <vector>
#include <queue>

using namespace std;

char str[1003][1003];

bool chk[1003][1003];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

#define r first
#define c second

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%s", str[i]);

	int cc = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j])continue;
			if (str[i][j] == '.')continue;

			queue <pair<int, int> > q;
			q.emplace(i, j);

			cc++;

			while (!q.empty()) {

				pair <int, int> f = q.front(); q.pop();

				for (int k = 0; k < 4; k++) {

					pair <int, int> g = { f.r + dr[k], f.c + dc[k] };

					if (g.r < 0 || g.r >= n || g.c < 0 || g.c >= n)continue;

					if (str[g.r][g.c] == '.')continue;

					if (chk[g.r][g.c])continue;

					chk[g.r][g.c] = true;

					q.emplace(g);

				}

			}
		}
	}

	printf("%d\n", cc);

}