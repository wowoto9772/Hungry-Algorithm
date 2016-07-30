#include <stdio.h>

int dp[10003];
bool p[10003];
int P[1503];

int main() {

	int top = 0;

	for (int i = 2; i <= 10000; i++) {
		if (!p[i]) {
			P[top++] = i;
			dp[i] = 1;
			for (int j = i*i; j <= 10000; j += i)p[j] = true;
		}
	}

	for (int j = 1; j < top; j++) {

		int s = 0;

		for (int k = 0; k <= j; k++)s += P[k];

		if (s > 10000)break;

		dp[s]++;

		for (int k = j + 1; k + j < top; k++) {
			s -= P[k - j - 1];
			s += P[k];
			if (s > 10000)break;
			dp[s]++;
		}

	}

	int n;
	while (scanf("%d", &n) == 1 && n) {
		printf("%d\n", dp[n]);
	}

}