#include <stdio.h>

int e[2003];
int dp[2003][2003];

int dy(int a, int b) {
	if (a >= b)return 1;
	if (dp[a][b] != -1)return dp[a][b];
	if (e[a] == e[b]) {
		return dp[a][b] = dy(a + 1, b - 1);
	}
	else {
		return dp[a][b] = 0;
	}
}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &e[i]);
		for (int j = i; j <= n; j++) {
			dp[i][j] = -1;
		}
	}

	int q;
	scanf("%d", &q);

	for (int i = 1; i <= q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", dy(a, b));
	}

}