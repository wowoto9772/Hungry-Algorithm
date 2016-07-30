#include <stdio.h>

int sum[5003];

int main() {

	for (int i = 1; i <= 5000; i++) {

		sum[i] = sum[i - 1];

		int m[10] = { 0 };

		int c = 1;

		int v = i;

		while (v) {
			int k = v % 10;
			m[k]++;
			if (m[k] == 2) {
				c = 0;
				break;
			}
			v /= 10;
		}

		sum[i] += c;

	}

	int a, b;
	while (scanf("%d %d", &a, &b) == 2) {
		printf("%d\n", sum[b] - sum[a - 1]);
	}

}