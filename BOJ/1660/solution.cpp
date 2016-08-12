#include <stdio.h>
#include <algorithm>

using namespace std;

int f[503];
int t[503];

int dp[300003];

int main() {

	int top = 0;

	for (int i = 1; i <= 122 && f[i] <= 300000; i++) {
		t[i] = t[i - 1] + i;
		f[i] = f[i - 1] + t[i];
		top = i;
	}

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j <= top && f[j] <= i; j++) {
			dp[i] = min(dp[i], dp[i - f[j]] + 1);
		}
	}

	printf("%d\n", dp[n]);

}