#include <stdio.h>
#define ll long long

bool isPrime(ll v) {
	if (!(v % 2)) {
		if (v == 2)return true;
		return false;
	}
	else {
		if (v == 1)return false;
		for (ll i = 3; i*i <= v; i += 2) {
			if (v%i)continue;
			return false;
		}return true;
	}
}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		ll v;
		scanf("%lld", &v);

		for (ll i = v;; i++) {
			if (isPrime(i)) {
				printf("%lld\n", i);
				break;
			}
		}

	}

}