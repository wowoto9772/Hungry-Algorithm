#include <stdio.h>

#define ll long long

class ele {
public:
	ll v;
	int i;
	ele() {}
	ele(ll _v, int _i) {
		v = _v, i = _i;
	}
};

ll max(ll a, ll b) {
	if (a < b)a = b;
	return a;
}

ll gcd(ll a, ll b) {
	ll m = 1;
	while (m) {
		m = a% b;
		a = b;
		b = m;
	}return a;
}

int s[2];
ele e[2][103];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		ll ans = 0;
		s[1 ^ 0] = 0;

		for (register int i = 0; i < n; i++) {

			ll v;
			scanf("%lld", &v);

			int c = i & 1;
			int p = 1 ^ c;

			e[p][s[p]++] = ele(v, i);
			s[c] = 0;

			for (register int j = 0; j < s[p]; j++) {
				ll g = gcd(e[p][j].v, v);
				ll qry = g * (i - e[p][j].i + 1);
				ans = max(ans, qry);
				if (s[c] > 0 && g == e[c][s[c] - 1].v)continue;
				e[c][s[c]++] = ele(g, e[p][j].i);
			}

		}

		printf("%lld\n", ans);

	}

}