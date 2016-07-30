#include <stdio.h>
#include <string.h>

#define ll long long

ll v(ll x) {

	if (!x)return 0;

	ll r = 1;

	while (x) {
		r *= x % 10;
		x /= 10;
	}

	return r;

}

char str[13];

int main() {

	scanf("%s", str);

	int s = strlen(str);

	if (s > 1) {

		ll n = 0;
		ll k;
		for (int i = 0; i < s - 1; i++) {
			n = n * 10 + str[i] - '0';
			ll k = 1;
			for (int j = i + 1; j < s; j++) {
				k *= str[j] - '0';
			}
			if (v(n) == k) {
				printf("YES\n");
				return 0;
			}
		}

	}

	printf("NO\n");

}