#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class BIT{
public:
	vector <int> T;
	int S;

	BIT(){}

	BIT(const int n){
		S = n;
		T.resize(S + 1);
	}

	void Update(int p, int v){
		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}
	}

	int Sum(int p){
		int ret = 0;
		while (p > 0){
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int x[100003];
int B[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &B[i]);

	BIT tree(n);

	for (int i = 1; i <= n; i++) {

		int l = 1, r = n, m;

		while (l <= r) {

			m = (l + r) / 2;

			int cmp = m - tree.Sum(m);

			if (cmp >= B[i] + 1)r = m - 1;
			else
				l = m + 1;

		}

		if (m - tree.Sum(m) < B[i] + 1)m++;

		x[m] = i;
		tree.Update(m, 1);

	}

	for (int i = 1; i <= n; i++)printf("%d\n", x[i]);

}