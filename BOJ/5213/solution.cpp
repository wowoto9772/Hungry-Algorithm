#include <stdio.h>
#include <memory.h>
#include <queue>

using namespace std;

class ele {
public:
	int a, c;
	ele() {}
	ele(int a_, int c_) { a = a_, c = c_; }
};

int c[755][1505];
int ind[755][1505];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int di[25005];
int rev[25005];

int main() {

	int n;
	scanf("%d", &n);

	int d = 0, e = 0;

	int top = 0;

	for (int i = 1; i <= n*n - n / 2; i++) {

		int a, b;
		scanf("%d %d", &a, &b);

		if (!(d & 1)) {
			ind[d][e] = ind[d][e + 1] = ++top;
			c[d][e] = a;
			c[d][e + 1] = b;
			e += 2;
			if (e / 2 == n) {
				e = 1;
				d++;
			}
		}
		else {
			ind[d][e] = ind[d][e + 1] = ++top;
			c[d][e] = a, c[d][e + 1] = b;
			e += 2;
			if (e / 2 == n - 1) {
				e = 0;
				d++;
			}
		}

	}

	vector < vector <int> > lnk;
	lnk.resize(top + 1);

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < 2 * n; j++) {
			int cur = ind[i][j];
			if (cur) {
				for (int k = 0; k < 4; k++) {
					int ni = i + dr[k], nj = j + dc[k];
					if (ni < 0 || nj < 0 || ni >= d || nj >= 2 * n)continue;
					int nxt = ind[ni][nj];
					if (nxt) {
						if (nxt != cur) {
							if (c[i][j] == c[ni][nj]) {
								lnk[cur].push_back(nxt);
								lnk[nxt].push_back(cur);
							}
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= top; i++)di[i] = -1;

	di[1] = 1;

	queue <ele> q;

	q.emplace(1, 1);

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		for (int j = 0; j < lnk[f.a].size(); j++) {

			ele g = { lnk[f.a][j], f.c + 1 };

			if (di[g.a] == -1) {
				di[g.a] = g.c;
				rev[g.a] = f.a;
				q.emplace(g);
			}

		}


	}

	for (int i = top; i >= 1; i--) {
		if (di[i] != -1) {
			printf("%d\n", di[i]);
			vector <int> out;
			int c = i;

			while (true) {
				out.push_back(c);
				if (c == 1)break;
				c = rev[c];
			}

			for (int j = out.size() - 1; j >= 0; j--)printf("%d ", out[j]);

			break;

		}
	}

}
