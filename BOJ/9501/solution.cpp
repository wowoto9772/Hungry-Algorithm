#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, d;
		scanf("%d %d", &n, &d);

		int c = 0;

		for (int i = 1; i <= n; i++) {

			int v, h, m;
			scanf("%d %d %d", &v, &h, &m);

			v *= h;
			v /= m;

			if (v >= d)c++;

		}

		printf("%d\n", c);

	}

}