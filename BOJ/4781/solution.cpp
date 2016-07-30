#include <stdio.h>
#include <string.h>
#include <algorithm>

#define ll long long

using namespace std;

ll dp[10003];
int p[5003], c[5003];

int par(char *z) {
	int s = strlen(z);
	int ret = 0;
	for (int i = 0; i < s; i++) {
		if (z[i] == '.')continue;
		ret = ret * 10 + z[i] - '0';
	}return ret;
}

int main() {

	char str[7] = { 0 };

	int n, m;

	while (scanf("%d %s", &n, str) == 2) {

		m = par(str);
		if (!n && !m)return 0;

		for (int i = 1; i <= n; i++) {
			scanf("%d %s", &p[i], str);
			c[i] = par(str);
		}

		for (int i = 1; i <= m; i++) {
			
			dp[i] = dp[i-1];

			for (int j = 1; j <= n; j++) {
				if (i - c[j] >= 0)dp[i] = max(dp[i], dp[i - c[j]] + p[j]);
			}

		}

		printf("%lld\n", dp[m]);

	}

}