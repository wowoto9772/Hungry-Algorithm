#include <stdio.h>
#include <limits.h>

#define ll long long

ll le[100003], ri[100003];
int way[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		scanf("%d", &way[i]);
		
	}

	for (int i = 2; i <= n; i++) {
		scanf("%lld", &le[i]);
		le[i] += le[i - 1];
	}

	for (int i = 2; i <= n; i++) {
		scanf("%lld", &ri[i]);
		ri[i] += ri[i - 1];
	}

	ll ans = LLONG_MAX;
	int k;

	for (int i = 1; i <= n; i++) {
		ll tmp = le[i] + way[i] + ri[n] - ri[i];
		if (ans > tmp) {
			ans = tmp;
			k = i;
		}
	}

	printf("%d %lld\n", k, ans);

}