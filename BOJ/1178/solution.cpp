#include <stdio.h>

int c[1003]; // degree

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);

	for (int i = 1; i <= e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		c[a]++, c[b]++;
	}
	// 연결되지 않아서, 연결 시켜야함
	// set & disjoint set

	int x = 0;

	for (int i = 0; i < v; i++) {
		if (c[i] % 2)x++;
	}

	if (x == 2 || x == 0)printf("0\n");
	else {
		printf("%d\n", (x - 2) / 2);
	}
}