#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

#define MV 100000

int dp[MV + 3];
int ri[MV + 3];

bool used[MV + 3];

int main() {

	int n;
	scanf("%d", &n);

	vector < pair<int, int> > v(n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end());

	int top = 0;

	for (int i = 0; i < n; i++) {

		ri[i] = -1;

		if (!top) {
			dp[top++] = i;
		}
		else {

			int l = 0, r = top - 1, m;

			int c;

			while (l <= r) {

				m = (l + r) / 2;

				c = dp[m];

				if (v[c].second < v[i].second) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}

			}

			c = dp[m];

			if (v[c].second < v[i].second)m++;

			dp[m] = i;

			if (m) {
				ri[i] = dp[m - 1];
			}

			top = max(m + 1, top);

		}
	}

	printf("%d\n", n - top);

	int x = dp[top - 1];

	while (x != -1) {
		used[x] = true;
		x = ri[x];
	}

	for (int i = 0; i < n; i++)if (!used[i])printf("%d\n", v[i].first);

}