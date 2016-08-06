#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int e[103];
int dp[100003 * 2];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &e[i]);
	}

	for (int i = 1; i <= e[n - 1] * 2; i++)dp[i] = INT_MAX;

	for (int i = 1; i <= e[n - 1] * 2; i++) {
		for (int j = 0; j < n; j++) {
			if (i - e[j] >= 0 && dp[i - e[j]] != INT_MAX) {
				dp[i] = min(dp[i], dp[i - e[j]] + 1);
			}
		}
	}

	bool flag = false;

	for (int i = 1; i <= e[n - 1] * 2; i++) {

		int c = i;

		int d = 0;

		for (int j = n - 1; j >= 0; ) {
			if (c >= e[j]) {
				d += c / e[j];
				c %= e[j];
			}
			else {
				j--;
			}
		}

		if (dp[i] < d) {
			flag = true;
			break;
		}

	}

	if (flag)printf("No\n");
	else
		printf("Yes\n");

}