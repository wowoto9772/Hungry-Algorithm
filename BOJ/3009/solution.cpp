#include <stdio.h>

int f[1003], s[1003];

int main() {

	int a, b;
	for (int i = 1; i <= 3; i++) {
		scanf("%d %d", &a, &b);

		f[a]++, s[b]++;
	}

	for (int i = 1; i <= 1000; i++) {
		if (f[i] == 1)printf("%d ", i);
	}

	for (int i = 1; i <= 1000; i++) {
		if (s[i] == 1)printf("%d ", i);
	}

}