#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll s[1000003];

int gcd(int a, int b) {

	int m = 1;

	while (m) {
		m = a % b;
		a = b;
		b = m;
	}

	return a;

}

bool chk[1003][1003];

int main() {

	vector < pair <int, pair<int, int> > > v;

	for (ll x = 1; x <= 500; x++) {
		for (ll y = 1; y < x; y++) {
			ll a = 2 * x*y;
			ll b = x*x - y*y;

			if (a <= b)continue;

			ll c = x*x + y*y;

			int g = gcd(a, gcd(b, c));

			a /= g, b /= g;

			if (2 * (a + b) <= 1000000) {
				v.push_back(make_pair(2 * (a + b), make_pair(a, b)));
			}
		}
	}

	sort(v.begin(), v.end());

	v.resize(unique(v.begin(), v.end()) - v.begin());

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		int c = 0;

		for (int i = 0; i < v.size() && n >= v[i].first; i++) {
			n -= v[i].first;
			c++;
		}
		
		printf("%d\n", c);

	}

}