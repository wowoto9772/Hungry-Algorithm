#include <stdio.h>
#include <vector>

using namespace std;

vector < vector <int> > lnk;

bool b[1003][1003];
int inv[100003];
int op[100003];
pair <int, int> invt[100003];

int ans[100003], tot, n, m, q;

bool vst[100003];

void dfs(int c) {

	if (vst[c])return;
	vst[c] = true;

	bool eff = true;

	int x, y;
	if (op[c] == 1) {
		x = invt[c].first, y = invt[c].second;
		if (!b[x][y]) {
			tot++;
			b[x][y] = true;
		}
		else {
			eff = false;
		}
	}
	else if (op[c] == 2) {
		x = invt[c].first, y = invt[c].second;
		if (b[x][y]) {
			tot--;
			b[x][y] = false;
		}
		else {
			eff = false;
		}
	}
	else if (op[c] == 3) {
		x = inv[c];
		for (int i = 1; i <= m; i++) {
			if (b[x][i]) {
				tot--;
				b[x][i] = false;
			}
			else if (!b[x][i]) {
				tot++;
				b[x][i] = true;
			}
		}
	}

	ans[c] = tot;
	for (int i = 0; i < lnk[c].size(); i++) {
		dfs(lnk[c][i]);
	}

	if (eff) {

		if (op[c] <= 2) {
			x = invt[c].first, y = invt[c].second;
			if (b[x][y]) {
				tot--;
				b[x][y] = false;
			}
			else {
				tot++;
				b[x][y] = true;
			}
		}
		else if (op[c] == 3) {
			x = inv[c];
			for (int i = 1; i <= m; i++) {
				if (b[x][i]) {
					tot--;
					b[x][i] = false;
				}
				else {
					tot++;
					b[x][i] = true;
				}
			}
		}

	}

}

int main() {

	scanf("%d %d %d", &n, &m, &q);

	lnk.resize(q + 1);

	for (int i = 1; i <= q; i++) {

		int t;
		scanf("%d", &t);

		op[i] = t;

		if (t <= 3) {

			lnk[i - 1].push_back(i);

			if (t <= 2) {

				int x, y;
				scanf("%d %d", &x, &y);

				invt[i] = { x, y };

			}
			else if (t == 3) {

				int x;
				scanf("%d", &x);

				inv[i] = x;

			}
		}
		else {

			int x;
			scanf("%d", &x);

			lnk[x].push_back(i);
		}

	}

	dfs(0);

	for (int i = 1; i <= q; i++)printf("%d\n", ans[i]);

}