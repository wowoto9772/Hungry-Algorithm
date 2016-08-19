#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define x first
#define y second

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

int x[1000003];
int y[1000003];

int main() {

	int n;
	scanf("%d", &n);

	vector < pair <int, int> > v(n);

	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);

		x[k] = i;
	}

	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);

		y[k] = i;
	}

	BIT tree(1000000);

	int top = 0;

	for (int i = 0; i <= 1000000; i++) {
		if (x[i]) {
			v[top++] = { x[i], y[i] };
			tree.Update(y[i], 1);
		}
	}

	sort(v.begin(), v.end());

	ll ans = 0;

	for (int i = v.size() - 1; i >= 0; i--) {
		tree.Update(v[i].y, -1);
		int tot = i - tree.Sum(v[i].y);
		ans += tot;
	}

	printf("%lld\n", ans);

}