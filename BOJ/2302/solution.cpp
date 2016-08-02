#include <stdio.h>

int dp[45];
bool spc[45];

int n;

int dy(int c) {

	if (c == n)return 1;
	else if (c > n)return 0;

	if (dp[c] != -1)return dp[c];

	dp[c] = 0;

	if (spc[c + 1] || spc[c + 2])dp[c] = dy(c + 1);
	else {
		dp[c] += dy(c + 2);
		dp[c] += dy(c + 1);
	}

	return dp[c];

}

int main() {

	scanf("%d", &n);

	int m;
	scanf("%d", &m);

	while (m--) {

		int a;
		scanf("%d", &a);

		spc[a] = true;

	}

	for (int i = 0; i <= n; i++)dp[i] = -1;

	printf("%d\n", dy(0));

}