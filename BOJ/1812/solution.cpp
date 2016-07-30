#include <stdio.h>

int c[1003];
int o[1003];

int main() {

	int n;
	scanf("%d", &n);

	int x = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		x += c[i];
	}

	x /= 2;

	for (int i = 1; i < n; i += 2) {
		x -= c[i];
	}

	o[n] = x;
	o[1] = c[n] - o[n];

	for (int i = 1; i < n - 1; i++) {
		o[i + 1] = c[i] - o[i];
	}

	for (int i = 1; i <= n; i++)printf("%d\n", o[i]);

	// ab
	// bc
	// ca

}