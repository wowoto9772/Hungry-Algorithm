#include <stdio.h>

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	int P = 1003, A = 1003;

	for (int i = 1; i <= m; i++) {

		int p, a;
		scanf("%d %d", &p, &a);
		if (P > p)P = p;
		if (A > a)A = a;

	}

	if (A * 6 >= P) {
		printf("%d\n", n / 6 * P + (((n % 6)*A < P) ? (n%6)*A : P));
	}
	else {
		printf("%d\n", n*A);
	}

}