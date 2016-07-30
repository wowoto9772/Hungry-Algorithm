#include <stdio.h>
#include <algorithm>

using namespace std;

int d(int v) {
	if (!v)return 1;
	int r = 0;
	while (v) {
		r++;
		v /= 10;
	}return r;
}

bool p[1000003] = { true, true, };

int t[] = { 1, 10, 100, 1000 };

int dp[1003][1003];

int main() {

	int n;
	scanf("%d", &n);

	int v = n + t[d(n)] * n;

	for (int i = 2; i*i <= v; i++) {
		if (p[i])continue;
		for (int j = i*i; j <= v; j += i)p[j] = true;
	}

	p[11] = true;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {

			int v = i*t[d(j)] + j;

			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + !p[v];

		}

	}

	printf("%d\n", dp[n][n]);

}