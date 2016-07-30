#include <stdio.h>
#include <queue>

using namespace std;

class ele {
public:
	int r, c, m;
	ele() {}
	ele(int a, int b, int k) {
		r = a, c = b, m = k;
	}
};

char str[53][53];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

bool chk[53][53];
int water[53][53];

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	queue <ele> q;

	ele s;

	for (int i = 0; i < r; i++) {
		scanf("%s", str[i]);
		for (int j = 0; j < c; j++) {
			if (str[i][j] == 'S') {
				s = { i, j, 0 };
			}
			else if (str[i][j] == '*') {
				water[i][j] = 1;
				q.emplace(i, j, 0);
			}
		}
	}

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {

			ele g = { f.r + dr[i], f.c + dc[i], f.m + 1 };

			if (g.r < 0 || g.c < 0 || g.r >= r || g.c >= c)continue;

			if (water[g.r][g.c])continue;

			if (str[g.r][g.c] == '.') {

				water[g.r][g.c] = g.m;

				q.emplace(g);
			}

		}

	}

	q.emplace(s);
	chk[s.r][s.c] = true;

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		if (str[f.r][f.c] == 'D') {
			printf("%d\n", f.m);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			
			ele g = { f.r + dr[i], f.c + dc[i], f.m + 1 };

			if (g.r < 0 || g.c < 0 || g.r >= r || g.c >= c)continue;

			if (chk[g.r][g.c])continue;
			if (str[g.r][g.c] == 'X')continue;

			if (!water[g.r][g.c] || g.m < water[g.r][g.c]) {

				chk[g.r][g.c] = true;
				q.emplace(g);

			}

		}


	}

	printf("KAKTUS\n");

}