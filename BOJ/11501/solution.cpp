#include <stdio.h>
#include <queue>

using namespace std;

#define ll long long

ll e[1000003];
ll s[1000003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		priority_queue < pair<int, int> > pq;

		for (int i = 1; i <= n; i++) {
			scanf("%lld", &e[i]);
			pq.emplace(e[i], i);
			s[i] = s[i - 1] + e[i];
		}

		ll ans = 0;

		int l = 0;

		while (!pq.empty()) {

			pair <int, int> c = pq.top(); pq.pop();

			if (l < c.second) {

				ll d = c.second - l - 1;

				if (d > 0) {
					ans += e[c.second] * d - (s[c.second - 1] - s[l]);
				}

				l = c.second;

			}

		}
			
		printf("%lld\n", ans);

	}

}