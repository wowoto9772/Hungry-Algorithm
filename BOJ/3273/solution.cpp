#include <stdio.h>
#define ll long long

int c[1000003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);

		c[a]++;
	}

	int x;
	scanf("%d", &x);

	ll ans = 0;

	int k = 0;

	if (!(x % 2))k = -1;

	for (int i = 1; i <= x / 2 + k; i++) {
		ans += (ll)c[i] * c[x - i];
	}

	if (k == -1) {
		ans += (ll)c[x/2] * (c[x/2] - 1) / 2;
	}

	printf("%lld\n", ans);

}