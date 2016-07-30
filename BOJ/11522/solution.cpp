#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int k, n;
		scanf("%d %d", &k, &n);

		printf("%d %d %d %d\n", k, (n*(n + 1)) / 2, (2*n)*n/2, 2 * (n*(n + 1)) / 2);

	}

}