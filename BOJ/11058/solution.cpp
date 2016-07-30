#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

ll dp[103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)dp[i] = i;

	for (int i = 4; i <= n; i++) {
		if (i >= 4) {
			for (int j = i; j <= n; j++) {
				dp[j] = max(dp[j], max((ll)dp[i-3]*(1 + (j - i + 1)), dp[j-3]*2));
			}
		}

	}

	printf("%lld\n", dp[n]);


}