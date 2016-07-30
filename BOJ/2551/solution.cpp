#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

ll c[10003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		c[a]++;
	}

	ll le, ri;
	le = ri = LLONG_MAX;

	int x, y;

	for (ll i = 1; i <= 10000; i++) {
		ll te = 0, mp = 0;
		for (ll j = 1; j <= 10000; j++) {
			te += abs(i - j) * c[j];
			mp += abs(i - j)*abs(i - j)*c[j];
		}
		if (le > te)le = te, x = i;
		if (ri > mp)ri = mp, y = i;
	}

	printf("%d %d\n", x, y);

}