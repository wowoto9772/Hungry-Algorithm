#include <stdio.h>

int o[33];

int main() {

	int a, b;
	scanf("%d %d", &a, &b);

	int m;
	scanf("%d", &m);

	int s = 1;

	for (int i = 1; i < m; i++) {
		s *= a;
	}

	int _a = 0;

	for (int i = 1; i <= m; i++) {

		int k;
		scanf("%d", &k);

		_a += s * k;
		s /= a;
	}

	int tp = 0;

	while (_a) {
		o[tp++] = _a % b;
		_a /= b;
	}

	for (int i = tp - 1; i >= 0; i--)printf("%d ", o[i]);

}