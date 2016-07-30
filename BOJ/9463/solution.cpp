#include <stdio.h>

#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

class BIT {
public:

	int S;

	vector <int> T;

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

int ma[100003], mb[100003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			int k;
			scanf("%d", &k);
			ma[k] = i;
		}

		for (int i = 1; i <= n; i++) {
			int k;
			scanf("%d", &k);
			mb[k] = i;
		}

		vector < pair <int, int> > sexy(n);

		BIT sa(n + 1), bb(n + 1);
		for (int i = 1; i <= n; i++) {
			sa.Update(i, 1);
			bb.Update(i, 1);
			sexy[i - 1] = make_pair(ma[i], mb[i]);
		}

		sort(sexy.begin(), sexy.end());

		ll ans = 0;

		for (int i = 0; i < n; i++) {

			sa.Update(sexy[i].first, -1);
			bb.Update(sexy[i].second, -1);

			int tot = (n - 1 - i);
			int a = sa.Sum(sexy[i].first);
			int b = bb.Sum(n) - bb.Sum(sexy[i].second);

			tot = (tot - (a+b));

			ans += tot;

		}

		printf("%lld\n", ans);

	}

}