#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

int dp[103];

int main() {

	int m[] = { 1, 10, 25 };

	dp[0] = 0;

	for (int i = 1; i <= 99; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; j < 3; j++) {
			if (i - m[j] >= 0) {
				dp[i] = min(dp[i], dp[i - m[j]] + 1);
			}
		}
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		ll n;
		scanf("%lld", &n);

		int c = 0;

		while (n) {

			int s = n % 100;

			c += dp[s];

			n /= 100;

		}

		printf("%d\n", c);

	}

}