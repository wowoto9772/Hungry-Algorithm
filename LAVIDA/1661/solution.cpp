#include <stdio.h>
#include <queue>
#include <time.h>

using namespace std;

class ele {
public:
	int r, c;
	ele() {}
	ele(int a, int b) { r = a, c = b; }
};

int dr[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int dc[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
bool chk[53][53] = { 0 };

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int r, c;
		scanf("%d %d", &r, &c);

		for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)chk[i][j] = false;


		queue <ele> q;
		q.emplace(0, 0);

		int m = 1;
		chk[0][0] = true;

		while (!q.empty()) {
			ele f = q.front(); q.pop();
			for (int i = 0; i < 8; i++) {
				ele g = { f.r + dr[i], f.c + dc[i] };
				if (g.r < 0 || g.c < 0 || g.r >= r || g.c >= c)continue;
				if (chk[g.r][g.c])continue;
				chk[g.r][g.c] = true;
				m++;
				q.emplace(g);
			}
		}


		printf("%d\n", m);
	}

}