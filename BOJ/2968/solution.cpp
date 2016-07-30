#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	// biggest divisor less then n

	for (int i = 2; i*i <= n; i++) {
		if (n%i)continue;
		printf("%d\n", n - 1 - (n / i) + 1);
		return 0;
	}

	printf("%d\n", n - 1);

}