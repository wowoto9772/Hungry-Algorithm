#include <stdio.h>

#define mid 10000000

int c[20000003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		int a;
		scanf("%d", &a);

		c[a + mid]++;

	}

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		int a;
		scanf("%d", &a);

		a += mid;

		printf("%d ", c[a]);

	}

}