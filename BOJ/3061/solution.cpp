#include <stdio.h>

int e[1003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)scanf("%d", &e[i]);

		int c = 0;

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (e[j] > e[j + 1]) {
					int k = e[j];
					e[j] = e[j + 1];
					e[j + 1] = k;
					c++;
				}
			}
		}

		printf("%d\n", c);

	}

}