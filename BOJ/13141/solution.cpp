#include <stdio.h>
#include <limits.h>

#include <functional>

#include <vector>
#include <queue>

#include <algorithm>

using namespace std;

class ele {
public:

	int a, b, c;

	ele() {}
	ele(int _a, int _b, int _c) {
		a = _a, b = _b, c = _c;
	}
};

int d[203][203];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	vector <ele> lnk;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)d[i][j] = INT_MAX;
		d[i][i] = 0;
	}

	for (int i = 1; i <= m; i++) {

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		lnk.emplace_back(a, b, c);
		lnk.emplace_back(b, a, c);

		d[a][b] = min(d[a][b], c);
		d[b][a] = d[a][b];
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((d[i][k] | d[k][j]) == INT_MAX)continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ans = INT_MAX;

	for (int i = 1; i <= n; i++) {

		int tmp = 0;

		for (int j = 0; j < lnk.size(); j++) {

			int s = lnk[j].a, a = lnk[j].b, c = lnk[j].c;

			if (d[i][s] + c == d[i][a]) {
				tmp = max(tmp, d[i][a] << 1);
			}
			else {
				int rem = (c + d[i][s] - d[i][a]);
				tmp = max(tmp, rem + (d[i][a] << 1));
			}

		}

		ans = min(ans, tmp);

	}

	printf("%d", ans >> 1);

	if (ans & 1)printf(".5");
	else
		printf(".0");

}