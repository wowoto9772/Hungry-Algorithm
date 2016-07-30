#include <stdio.h>
int main()
{

	int n;
	scanf("%d", &n);

	int L = 2, R = 7;
	int c = 1;
	while (L <= n) {
		L += 6 * c;
		R += 6 * (++c);
	}

	printf("%d\n", c);
}