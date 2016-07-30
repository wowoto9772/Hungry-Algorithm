#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#define ll long long

using namespace std;

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
	ll Sum(int p) {
		ll ret = 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};


int main()
{

	int n;
	while (scanf("%d", &n) == 1 && n) {

		BIT tree(n);

		priority_queue < pair <int, int>, vector<pair<int, int> >, greater<pair<int, int> > >a;
		for (int i = 1; i <= n; i++) {

			int s;
			scanf("%d", &s);

			a.push(make_pair(s, i));
			tree.Update(i, 1);
		}

		ll ans = 0;

		while (!a.empty()) {
			int f = a.top().second;
			ans += tree.Sum(f - 1);
			tree.Update(f, -1);
			a.pop();
		}

		printf("%lld\n", ans);
	}
}