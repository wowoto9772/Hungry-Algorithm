#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long

void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) {
		d = a; x = 1; y = 0;
	}
	else {
		exgcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

/* find a pair (c,d) s.t. ac + bd = gcd(a,b)
* Dependencies: none */
pair <ll, ll> extended_gcd(ll a, ll b) {
	if (b == 0) return make_pair(1, 0);
	pair <ll, ll> t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

ll a, b, s, d, x, y;
void work() {

	if (a > b) {
		ll k = a;
		a = b;
		b = k;
	}

	if (!a) {
		if (!b) {
			printf("%s\n", s ? "NO" : "YES");
		}
		else {
			printf("%s\n", s % b ? "NO" : "YES");
		}
	}

	exgcd(a, b, d, x, y);

	if (s % d) {
		puts("NO");
		return;
	}

	a /= d; b /= d; s /= d;
	x *= s % b; x %= b;

	while (x < 0) x += b;

	y = (s - a * x) / b;
	while (y >= 0) {
		if (gcd(x, y) == 1) {
			puts("YES");
			return;
		}
		x += b; y -= a;
	}

	puts("NO");
}
int main() {
	while (scanf("%lld %lld %lld", &a, &b, &s) == 3) {
		work();
	}
	return 0;
}