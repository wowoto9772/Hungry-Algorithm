#include <stdio.h>
#include <limits.h>
#include <algorithm>

#define ll long long

using namespace std;

int dp[320003];

int l[17], r[17];

int main() {

	for (int i = 1; i <= 320000; i++)dp[i] = INT_MAX;

	for (ll i = 1; i <= 320000; i++) {
		for (ll j = i; j*i <= 320000; j++) {
			dp[i*j] = min(dp[i*j], (int)(j - i));
		}
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)scanf("%d", &r[i]);
		for (int i = 0; i < n; i++)scanf("%d", &l[i]);

		int s = (1 << n);

		int ans = INT_MAX;

		for (int i = 1; i < s; i++) {

			int rrr = 0, lll = 0;

			for (int j = 0; j < n; j++) {

				if (i & (1 << j)) {
					rrr += r[j];
					lll += l[j];
				}

			}

			if (abs(rrr - lll) <= 1) {
				ans = min(ans, dp[lll + rrr]);
			}

		}

		if (ans == INT_MAX)ans = -1;

		printf("%d\n", ans);

	}

}