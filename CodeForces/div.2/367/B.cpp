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
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int main() {

	int n;
	scanf("%d", &n);

	BIT tree(100003);

	for (int i = 1; i <= n; i++) {

		int e;
		scanf("%d", &e);

		tree.Update(e, 1);
	}

	int q;
	scanf("%d", &q);

	while (q--) {

		int x;
		scanf("%d", &x);

		if (x > 100000)x = 100001;

		printf("%d\n", tree.Sum(x));

	}

}