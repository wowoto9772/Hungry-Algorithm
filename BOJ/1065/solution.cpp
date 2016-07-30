#include <stdio.h>

int main() {


	int n;
	scanf("%d", &n);

	int m = 0;

	for (int i = 1; i <= n; i++) {

		int c = i;
		int l = c % 100 / 10;
		int d = (c % 10) - l;
		c /= 100;

		bool flag = false;

		while (c) {
			if (l - d != c % 10)flag = true;
			l = c % 10;
			c /= 10;
		}

		if (!flag)m++;

	}

	printf("%d\n", m);

}