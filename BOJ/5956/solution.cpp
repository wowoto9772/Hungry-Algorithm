#include <stdio.h>

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	int m = 0;

	while (r & 1 && c & 1) {

		m++;

		r = (r - 1) >> 1;
		c = (c - 1) >> 1;

	}

	int ans = 0;

	int k = 1;

	for (int i = 1; i <= m; i++) {
		ans += k;
		k <<= 2;
	}

	printf("%d\n", ans);

}