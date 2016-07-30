#include <stdio.h>
#include <queue>

using namespace std;

int dx[][4] = { { 0,0,1,2 },{ 0,3,4,5 },{ 0,6,7,8 },{ 0,0,3,6 },{ 0,1,4,7 },{ 0,2,5,8 },{ 0,0,4,8 },{ 0,2,4,6 } };

int main() {

	for (int i = 0; i < 8; i++) {
		for (int j = 1; j <= 3; j++)dx[i][0] |= 1 << dx[i][j];
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		bool chk[(1 << 9)] = {};

		int k = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char c;
				scanf(" %c", &c);

				if (c == 'H')k |= 1 << (i * 3 + j);
			}
		}

		queue <int> q, c;

		q.push(k);
		c.push(0);

		bool ends = false;

		while (!q.empty()) {

			int f = q.front(); q.pop();
			int ff = c.front(); c.pop();

			if (f == 0 || f == (1 << 9) - 1) {
				printf("%d\n", ff);
				ends = true;
				break;
			}

			for (int i = 0; i < 8; i++) {
				int g = f ^ dx[i][0];
				if (chk[g])continue;
				chk[g] = true;
				q.push(g);
				c.push(ff + 1);
			}

		}

		if (!ends)printf("-1\n");

	}

}