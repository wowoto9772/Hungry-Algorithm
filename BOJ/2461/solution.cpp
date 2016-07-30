#include <stdio.h>
#include <limits.h>

#include <vector>
#include <algorithm>

using namespace std;

int c[1003];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	vector < pair<int, int> > e;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v;
			scanf("%d", &v);
			e.emplace_back(v, i);
		}
	}

	sort(e.begin(), e.end());

	int l = 0, r = 0;
	c[e[0].second]++;
	int k = 1;

	int ans = INT_MAX;

	while (l <= r && r < n*m) {

		if (k < n) {

			r++;

			if (r >= n*m)break;

			int m = e[r].second;
			if (!c[m])k++;
			c[m]++;

		}
		else {

			ans = min(e[r].first - e[l].first, ans);

			int m = e[l].second;
			c[m]--;

			if (!c[m])k--;

			l++;

		}

	}

	printf("%d\n", ans);

}