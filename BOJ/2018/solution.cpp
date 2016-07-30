#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	n <<= 1;

	int c = 0;
	for (int i = 1; i*i <= n; i++) {

		if (n%i)continue;

		int k = n / i;

		k += 1 - i;
		if (k % 2)continue;
		c++;

	}

	printf("%d\n", c);
	
}