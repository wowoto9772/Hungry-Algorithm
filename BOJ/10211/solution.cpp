#include <stdio.h>
#include <limits.h>

int main() {

	int t;
	scanf("%d", &t);

	for (int k = 1; k <= t; k++) {

		int n;
		scanf("%d", &n);

		int ans = INT_MIN;
		int sum = 0;

		for (int i = 1; i <= n; i++) {
			
			int a;
			scanf("%d", &a);

			sum += a;

			if (ans < sum)ans = sum;
			if (sum < 0)sum = 0;

		}

		printf("%d\n", ans);

	}

}