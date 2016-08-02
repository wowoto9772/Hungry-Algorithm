#include <stdio.h>

int main() {

	int tc = 0;

	int n;
	while (scanf("%d", &n) == 1 && n) {

		double c = 987654321.0;
		int x;

		for (int i = 1; i <= n; i++) {
			int d, p;
			scanf("%d %d", &d, &p);

			double k = p / (double)(d*d);

			if (c > k)c = k, x = d;
		}

		printf("Menu %d: %d\n", ++tc, x);

	}

}