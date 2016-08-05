#include <stdio.h>

bool p[123457 * 2] = { true, true };
int s[123457 * 2];

int main() {

	for (int i = 2; i*i <= 123456 * 2; i++) {
		if (p[i])continue;
		for (int j = i*i; j <= 123456 * 2; j += i)p[j] = true;
	}

	for (int i = 2; i <= 123456 * 2; i++) {
		s[i] = s[i - 1] + !p[i];
	}

	int n;
	while (scanf("%d", &n) == 1 && n) {

		printf("%d\n", s[n << 1] - s[n]);

	}

}