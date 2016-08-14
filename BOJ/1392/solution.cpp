#include <stdio.h>

int t[10003];

int main() {

	int n, q;
	scanf("%d %d", &n, &q);

	int c = 0;

	for (int i = 1; i <= n; i++) {

		int x;
		scanf("%d", &x);

		for (int j = c; j <= c + x; j++) {
			t[j] = i;
		}

		c += x;

	}

	while (q--) {

		int k;
		scanf("%d", &k);

		printf("%d\n", t[k]);

	}

}