#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

ll x[1000003], y[1000003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		ll n, m;
		scanf("%lld %lld", &n, &m);

		for (int i = 0; i < n; i++)scanf("%lld", &x[i]);
		for (int i = 0; i < m; i++)scanf("%lld", &y[i]);

		sort(x, x + n);
		sort(y, y + m);

		ll ans = LLONG_MAX, w;

		ll ul = n, ur = m;
		ll dl = 0, dr = 0;

		ll sul = 0, sur = 0, sdl = 0, sdr = 0;

		for (int i = 0; i < n; i++)sul += x[i];
		for (int i = 0; i < m; i++)sur += y[i];
		x[n] = y[m] = INT_MAX;

		int l = 0, r = 0;

		ll c;

		while (true) {

			if (l == n && r == m)break;
			else if (x[l] > y[r]) {
				// only r
				c = y[r];
				sur -= y[r];
				sdr += y[r];
				r++;
				dr++;
				ur--;
			}
			else{
				// only l
				c = x[l];
				sul -= x[l];
				sdl += x[l];
				l++;
				dl++;
				ul--;
			}

			ll k = m * (sul - ul * c + dl * c - sdl) + n * (sur - ur * c + dr * c - sdr);

			if (ans > k) {
				ans = k;
				w = c;
			}

		}

		printf("%d.0\n", w);

	}

}