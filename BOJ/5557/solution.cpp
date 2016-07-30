#include <stdio.h>
#include <memory.h>

#define ll long long

int n;
int a[103];

ll dp[23][103];

ll dy(int s, int c) {

	if (c == n) {
		return s == a[n];
	}

	if (dp[s][c] != -1)return dp[s][c];

	dp[s][c] = 0;

	if (s + a[c] <= 20)dp[s][c] += dy(s + a[c], c + 1);
	if (s - a[c] >= 0)dp[s][c] += dy(s - a[c], c + 1);

	return dp[s][c];

}

int main() {


	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

	memset(dp, 0xff, sizeof(dp));

	printf("%lld\n", dy(a[1], 2));

}