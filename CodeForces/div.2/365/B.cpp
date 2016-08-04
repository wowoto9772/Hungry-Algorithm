#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long

bool s[100003];
ll c[100003];

class BIT {
public:
	vector <int> T;
	int S;

	BIT(const int n) {
		S = n;
		T.resize(S + 1);
	}

	void Update(int p, int v) {
		while (p <= S) {
			T[p] += v;
			p += p & (-p);
		}
	}

	long long Sum(int p) {
		long long ret = 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
	}

	c[n + 1] = c[1];

	BIT tree(n);

	for (int i = 1; i <= k; i++) {

		int x;
		scanf("%d", &x);

		tree.Update(x, c[x]);

		s[x] = true;

	}

	ll ans = 0;

	ll se = 0, xy = 0;

	for (int i = 1; i <= n; i++) {
		
		int nxt = i + 1;

		if (nxt > n)nxt = 1;

		if (i <= n && (s[i] || s[nxt])) {
			
		}
		else {
			ans += c[i] * c[i + 1];
		}

		if (s[i]) {
			ans += (tree.Sum(n) - tree.Sum(i)) * c[i];
			se += c[i];
		}
		else {
			xy += c[i];
		}

	}

	printf("%lld\n", ans + se * xy);

}