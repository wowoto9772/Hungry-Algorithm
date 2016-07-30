#include <stdio.h>
#define mod 1000000007

char str[300003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	scanf("%s", str);

	int pt = 0;

	int v = 0;

	for (int i = 0; i < n; i++) {

		v = v * 10 + str[i] - '0';

		v %= k;

		if (!v)pt++;

	}

	// nC0 + nC1 + nC2 + ... + nCn = 2^n

	int g;

	if (!v)g = 1;
	else
		g = 0;

	// last fixedd
	for (int i = 1; i < pt; i++) {
		g <<= 1;
		g %= mod;
	}

	printf("%d\n", g);

}
