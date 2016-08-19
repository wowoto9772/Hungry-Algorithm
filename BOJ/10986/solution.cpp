#include <stdio.h>

#define ll long long

int c[2003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	int s = 0;

	for (int i = 1; i <= n; i++) {

		int v;
		scanf("%d", &v);

		s += v;
		s %= k;

		c[s]++;

	}

	/*
	first remainder k ~~ second remainder k ~ ... nth remainder k
	then, all cases are n C 2
	*/


	c[0]++; // base

	ll ans = 0;

	for (int i = 0; i < k; i++) {
		ans += 1LL * c[i] * (c[i] - 1) / 2LL;
	}

	printf("%lld\n", ans);

}