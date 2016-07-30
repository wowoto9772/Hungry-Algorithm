#include <stdio.h>

int a[100003];

int main() {

	int n, s;
	scanf("%d %d", &n, &s);

	for (int i = 1; i <= n; i++) {
		int g;
		scanf("%d", &g);
		a[i] = a[i - 1] + g;
	}

	for (int i = 1; i < n; i++) {

		int l = 1, r = (n - i + 1) / 2, m;

		while (l <= r) {
			m = (l + r) / 2;
			if (i + 2 * m - 1 <= n && a[i + m - 1] - a[i - 1] <= s && a[i + 2 * m - 1] - a[i + m - 1] <= s)l = m + 1;
			else
				r = m - 1;
		}

		if (a[i + m - 1] - a[i - 1] > s || a[i + 2 * m - 1] - a[i + m - 1] > s)m--;

		printf("%d\n", 2 * m);

	}

	printf("0\n");

}