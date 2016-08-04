#include <stdio.h>

#define ll long long

ll se[1000003], xy[1000003];

int c[22];

int n, m;

void data(int x) {

	if (c[0]) {
		for (int i = 0; i < x; i++) {
			c[n - 1 - i] = c[i];
		}
		int v = 0;
		for (int i = 0; i < 2*n; i++) {
			v = v * 10 + c[i];
			v %= m;
		}
		se[v]++;
	}

	for (int i = 0; i < x; i++) {
		c[n - 1 - i] = c[i];
	}
	int v = 0;
	for (int i = 0; i < n; i++) {
		v = v * 10 + c[i];
		v %= m;
	}

	xy[v]++;

}

void make(int x) {

	if (x == (n >> 1)) {

		if (n&1) {

			for (int i = 0; i < 10; i++) {

				c[x] = i;

				data(x);

			}

		}
		else {

			data(x);

		}

		return;
	}
	else {
		for (int i = 0; i < 10; i++) {
			c[x] = i;
			make(x + 1);
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);

	n >>= 1;

	make(0);

	ll ans = 0;

	for (int i = 0; i < m; i++) {
		ans += se[i] * xy[(m - i) % m];
	}

	printf("%lld\n", ans);

}

// a * 10^(n/2) + b
// a%m + b%m