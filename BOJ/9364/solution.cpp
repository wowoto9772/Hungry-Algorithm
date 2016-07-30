#include <stdio.h>
#include <string.h>

#define ll long long

char str[100003];

ll ans;

int compute(int p, int s, ll x) {

	ll v = 0;

	ll C = 0, E = 0;

	int sig = 0;

	bool ngn = false; // negative sign
	bool exp = false; // exponential

	for (int i = p; i < s; i++) {

		if (str[i] == '+' || str[i] == '-') {
			sig++;
			if (sig == 2) {

				// CX

				// compute expression

				ans += C * x;

				return i;
			}
			if (str[i] == '-')ngn = true;
		}
		else if (str[i] == '^') {
			E = 0;
		}
		else if (str[i] == 'X') {

			if (!C) {
				C = 1;
				if (ngn)C *= -1;
			}

			if (i == s - 1) {
				ans += C*x;
				return s;
			}

			exp = true;

		}
		else {

			// parsing values

			if (sig == 0)sig++;

			for (int j = i; j < s; j++) {
				if (str[j] >= '0' && str[j] <= '9') {
					v = v * 10LL + str[j] - '0';
					if (j == s - 1) {
						i = j;
						break;
					}
				}
				else {
					i = j - 1;
					break;
				}
			}

			if (ngn) {
				v *= -1LL;
				ngn = false;
			}

			if (exp) {
				E = v;
				exp = false;
				
				ll k = 1;
				for (int j = 1; j <= E; j++)k *= x;
				ans += k * C;

				return i + 1;
			}
			else if (i + 1 < s && str[i + 1] == 'X') {
				C = v;
			}
			else if (i == s - 1) {
				ans += v;
				return s;
			}

			v = 0;

		}
	}

}

int main() {

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		ll x;
		scanf("%lld", &x);

		scanf("%s", str);

		int s = strlen(str);

		ans = 0;

		for (int i = 0; i < s; ) {
			i = compute(i, s, x);
		}

		printf("Case #%d: %lld\n", ++tc, ans);

	}

}