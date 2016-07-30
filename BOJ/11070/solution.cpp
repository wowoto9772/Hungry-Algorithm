#include <stdio.h>
#include <limits.h>
#include <algorithm>

#define ll long long

using namespace std;

ll a[1003], s[1003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)a[i] = s[i] = 0;

		for (int i = 1; i <= m; i++) {

			int x, y, p, q;
			scanf("%d %d %d %d", &x, &y, &p, &q);

			a[x] += p, s[x] += q;
			a[y] += q, s[y] += p;

		}

		ll MM = 0, mm = LLONG_MAX;

		for (int i = 1; i <= n; i++) {

			ll w;

			if (!a[i] && !s[i])w = 0;
			else
				w = (a[i] * a[i]) * 1000LL / (a[i] * a[i] + s[i] * s[i]);

			MM = max(w, MM);
			mm = min(w, mm);

		}

		printf("%lld\n%lld\n", MM, mm);

	}

}