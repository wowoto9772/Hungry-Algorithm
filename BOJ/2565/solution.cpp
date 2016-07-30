#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int dp[103];

int main() {

	int n;
	scanf("%d", &n);

	vector < pair <int, int> > v(n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end());

	int ans = n;

	for (int i = 0; i < n; i++) {

		dp[i] = 1;

		for (int j = 0; j < i; j++) {

			if (v[j].first < v[i].first) {
				if (v[j].second < v[i].second) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}

		}

		ans = min(ans, n - dp[i]);

	}

	printf("%d\n", ans);

}