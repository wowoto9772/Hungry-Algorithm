#include <vector>
#include <stdio.h>
#include <algorithm>

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

	long long Sum(int p) {
		long long ret = 0;
		if (p == 0)return 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}

};

int main() {

	int n;
	scanf("%d", &n);

	BIT tree(n);

	for (int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &v);

		tree.Update(i, v);
	}

	int q;
	scanf("%d", &q);

	while(q--){

		int t, x;
		scanf("%d %d", &t, &x);

		if (t == 1) {

			int a;
			scanf("%d", &a);

			tree.Update(x, a);
		}
		else {

			int l = 1, r = n, m;

			int v = 0;

			while (l <= r) {

				m = (l + r) / 2;

				if (tree.Sum(m - 1) < x && x <= tree.Sum(m)) {
					printf("%d\n", m);
					break;
				}

				if (tree.Sum(m) > x)r = m - 1;
				else {
					l = m + 1;
				}

			}

		}

	}

}