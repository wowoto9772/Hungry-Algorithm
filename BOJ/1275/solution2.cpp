#include <stdio.h>

#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

class BIT {
public:

	vector <ll> T;
	int S;

	BIT(const int n) {
		S = n;
		T.resize(S + 1);
	}

	void Update(int p, ll v) {
		while (p <= S) {
			T[p] += v;
			p += p & (-p);
		}
	}

	long long Sum(int p) {
		if (p == 0)return 0;
		long long ret = 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}

};

ll e[100003];

int main() {

	int n, q;
	scanf("%d %d", &n, &q);

	BIT tree(n);

	for (int i = 1; i <= n; i++) {

		ll v;
		scanf("%lld", &v);

		tree.Update(i, v);
		e[i] = v;

	}

	while (q--) {

		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);

		if (x > y)swap(x, y);

		printf("%lld\n", tree.Sum(y) - tree.Sum(x-1));

		tree.Update(a, -e[a]);
		e[a] = b;
		tree.Update(a, e[a]);

	}

}