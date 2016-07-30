#include <stdio.h>
#include <queue>

using namespace std;

class ele {
public:
	int h, w, k, c;
	ele() {}
	ele(int a, int b, int e, int f) { h = a, w = b, k = e, c = f; }
};

bool chk[203][203][33];
int a[203][203];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int mdr[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int mdc[] = { 1, -1, 2, -2,  2, -2, 1, -1 };

int main() {

	int k;
	scanf("%d", &k);

	int w, h;
	scanf("%d %d", &w, &h);

	for (int i = 1; i <= h; i++)for (int j = 1; j <= w; j++)scanf("%d", &a[i][j]);

	queue <ele> q;
	q.emplace(1, 1, k, 0);

	chk[1][1][k] = true;

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		if (f.h == h && f.w == w) {

			printf("%d\n", f.c);

			return 0;

		}

		if (f.k) {

			for (int i = 0; i < 8; i++) {

				ele g = { f.h + mdr[i], f.w + mdc[i], f.k - 1, f.c + 1 };

				if (g.h < 1 || g.w < 1 || g.h > h || g.w > w)continue;
				
				if (a[g.h][g.w])continue;

				if (chk[g.h][g.w][g.k])continue;

				chk[g.h][g.w][g.k] = true;

				q.emplace(g);

			}

		}

		for (int i = 0; i < 4; i++) {

			ele g = { f.h + dr[i], f.w + dc[i], f.k, f.c + 1 };

			if (g.h < 1 || g.w < 1 || g.h > h || g.w > w)continue;

			if (a[g.h][g.w])continue;

			if (chk[g.h][g.w][g.k])continue;

			chk[g.h][g.w][g.k] = true;

			q.emplace(g);

		}	

	}

	printf("-1\n");

}