#include <stdio.h>

int e[1003];

int main() {

	int n;
	scanf("%d", &n);

	int c = 0, k;

	for (int i = 1; i <= n; i++) {

		scanf("%d", &e[i]);

		if (c < e[i]) {
			c = e[i];
			k = i;
		}

	}

	int ans = 0;

	for (int i = k - 1; i >= 1; i--) {

		ans += e[k] + e[i];

	}

	for (int i = k + 1; i <= n; i++) {

		ans += e[k] + e[i];

	}

	printf("%d\n", ans);

}