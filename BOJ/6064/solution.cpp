#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);

		bool flag = false;

		for (int i = 0; i < m; i++) {
			int d = (n * i + y) % m;
			if (!d)d = m;
			if (d == x) {
				printf("%d\n", i*n + y);
				flag = true;
				break;
			}
		}

		if (!flag)printf("-1\n");

	}

}
