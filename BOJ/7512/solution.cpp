#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

bool p[10000000];
int P[700000];
ll S[700000];
int x[11], top;

bool isPrime(ll v) {
	if (v == 2)return true;
	else if (!(v % 2))return false;
	else {
		if (v < 2)return false;
		for (ll i = 3; i*i <= v; i += 2) {
			if (v%i)continue;
			return false;
		}
		return true;
	}
}

int main()
{
	for (int i = 2; i*i < 10000000; i++) {
		if (!p[i]) {
			for (int j = i + i; j < 10000000; j += i)p[j] = true;
		}
	}

	for (int i = 2; i < 10000000; i++) {
		if (!p[i]) {
			S[top] = i;
			if (top)S[top] += S[top - 1];
			P[top++] = i;
		}
	}

	int t;
	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++) {

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
		}

		sort(x, x + n);

		for (int i = 0; i + x[n - 1] < top; i++) {

			ll cmp = S[i + x[n - 1] - 1];
			if (i)cmp -= S[i - 1];

			if (!isPrime(cmp))continue;

			bool fin = false;
		
			if (n == 1)fin = true;

			for (int j = n - 2; j >= 0 && !fin; j--) {
				bool pos = false;
				int l = 0, r = top - x[j], m;
				while (l <= r && !pos) {
					m = (l + r) / 2;
					ll tmp = S[m + x[j] - 1];
					if (m)tmp -= S[m - 1];
					if (tmp < cmp)l = m + 1;
					else if (tmp > cmp)r = m - 1;
					else {
						pos = true;
					}
				}
				if (!pos)break;
				else {
					if (j == 0) {
						fin = true;
					}
				}
			}

			if (fin) {
				printf("Scenario %d:\n%lld\n\n", tc, cmp);
				break;
			}

		}

	}
}