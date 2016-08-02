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

		x[n] = y[m] = INT_MAX;

		int l = 0, r = 0;

		int c, p = min(x[l], y[r]);

		if (x[l] == p)l++;
		if (y[r] == p)r++;

		long long pre = 0;

		bool flag = false;

		while (true) {

			if (l >= n && r >= m)break;
			else {
				c = min(x[l], y[r]);
			}

			long long dy = c - p;

			long long cur = (l*m*dy + r*n*dy) - ((n - l) * m * dy + (m - r) * n * dy);

			cur = dy * (l*m + r*n - (n - l)*m - (m - r)*n);
			cur = dy * (2LL * m*l + 2LL * r*n - 2LL * n*m);
			cur = 2LL * dy * (m*l + r*n - n*m);
			cur = dy * (m*l + r*n - n*m);

			if (cur < 0)pre = cur;
			else {
				break;
			}

			p = c;

			if (x[l] == c)l++;
			if (y[r] == c)r++;

		}

		printf("%d.0\n", p);

	}

}