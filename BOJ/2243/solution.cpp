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


	BIT tree(1000003);

	int q;
	scanf("%d", &q);

	while(q--){

		int t, x;
		scanf("%d %d", &t, &x);

		if (t == 2) {

			int a;
			scanf("%d", &a);

			tree.Update(x, a);

		}
		else {

			// x-th what

			int l = 1, r = 1000000, m;

			while (l <= r) {

				m = (l + r) / 2;

				if (tree.Sum(m - 1) < x && x <= tree.Sum(m)) {

					printf("%d\n", m);

					tree.Update(m, -1);

					break;

				}

				if (tree.Sum(m) >= x)r = m - 1;
				else
					l = m + 1;

			}

		}

	}

}