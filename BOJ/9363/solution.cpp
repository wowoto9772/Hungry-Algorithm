#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long
#define lim 1000000

bool p[lim + 3];

int main() {

	for (int i = 2; i*i <= lim; i++) {
		if (p[i])continue;
		for (int j = i*i; j <= lim; j += i) {
			p[j] = true;
		}
	}

	vector <int> P;

	for (int i = 2; i <= lim; i++)if (!p[i])P.push_back(i);

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		int a, b;
		scanf("%d %d", &a, &b);

		vector <int> C(1000003);

		for (int i = 1; i <= a; i++) {
			int k;
			scanf("%d", &k);

			for (int i = 2; i*i <= k; i++) {
				if (k%i)continue;
				while (!(k%i)) {
					C[i]++;
					k /= i;
				}
			}

			if (k != 1)C[k]++;
		}

		for (int i = 1; i <= b; i++) {
			int k;
			scanf("%d", &k);

			for (int i = 2; i*i <= k; i++) {
				if (k%i)continue;
				while (!(k%i)) {
					C[i]--;
					k /= i;
				}
			}

			if (k != 1)C[k]--;
		}

		ll s = 1, m = 1;
		for (ll i = 2; i <= 1000000; i++) {
			while (C[i] > 0) {
				s *= i;
				C[i]--;
			}
			while (C[i] < 0) {
				m *= i;
				C[i]++;
			}
		}

		printf("Case #%d: %lld / %lld\n", ++tc, s, m);

	}

}