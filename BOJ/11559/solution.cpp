#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define r first
#define c second

char str[15][8];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

bool Bomb() {

	bool chk[15][8] = { 0 };

	int py = 0;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			
			if (chk[i][j])continue;
			if (str[i][j] == '.')continue;

			int cc = 1;

			queue < pair <int, int> > q;

			chk[i][j] = true;
			q.emplace(i, j);

			while (!q.empty()) {

				pair <int, int> f = q.front(); q.pop();

				for (int k = 0; k < 4; k++) {
					pair <int, int> g = { f.r + dr[k], f.c + dc[k] };
					if (g.r < 0 || g.r >= 12 || g.c < 0 || g.c >= 6)continue;
					
					if (chk[g.r][g.c])continue;

					if (str[g.r][g.c] == str[i][j]) {
						chk[g.r][g.c] = true;
						q.emplace(g);
						cc++;
					}
				}

			}

			if (cc >= 4) {
				queue < pair <int, int> > q;
				q.emplace(i, j);

				while (!q.empty()) {

					pair <int, int> f = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						pair <int, int> g = { f.r + dr[k], f.c + dc[k] };
						if (g.r < 0 || g.r >= 12 || g.c < 0 || g.c >= 6)continue;
						if (g.r == i && g.c == j)continue;

						if (str[g.r][g.c] == str[i][j]) {
							str[g.r][g.c] = '.';
							q.emplace(g);
						}
					}

				}
				
				str[i][j] = '.';

				py++;

			}

		}
	}

	return py;

}

void Down() {

	for (int i = 0; i < 6; i++) {
		for (int j = 11; j >= 0; j--) {
			if (str[j][i] == '.') {
				for (int k = j - 1; k >= 0; k--) {
					if (str[k][i] != '.') {
						str[j][i] = str[k][i];
						str[k][i] = '.';
						break;
					}
				}
			}
		}
	}

}

int main() {

	for (int i = 0; i < 12; i++)scanf("%s", str[i]);

	Down();

	int cc = 0;

	while (true) {

		if (Bomb()) {
			cc++;
			Down();
		}
		else {
			break;
		}

	}

	printf("%d\n", cc);

}