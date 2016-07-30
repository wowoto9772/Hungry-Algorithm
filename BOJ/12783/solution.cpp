#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXV 987654321

int all;
int dp[1000003];

int dy(int v) {

	if (dp[v] != -1)return dp[v];

	int cv = v;
	int cur = 0;

	while (cv) {
		cur |= 1 << (cv % 10);
		cv /= 10;
	}

	if ((cur & all) == cur)dp[v] = 0;
	else
		dp[v] = MAXV;

	for (int i = 2; i*i <= v; i++) {
		if (v%i)continue;
		dp[v] = min(dp[v], 1 + dy(i) + dy(v / i));
	}

	return dp[v];

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		all = 0;
		for (int i = 0; i < n; i++) {

			int k;
			scanf("%d", &k);

			all |= 1 << k;
		}

		for (int i = 1; i <= 1000000; i++)dp[i] = -1;

		int q;
		scanf("%d", &q);

		while (q--) {

			int x;
			scanf("%d", &x);

			int y = dy(x);

			if (y >= MAXV)y = -1;
			
			printf("%d\n", y);

		}

	}

}