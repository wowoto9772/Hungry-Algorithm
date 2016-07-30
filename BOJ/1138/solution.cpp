#include <stdio.h>
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
	long long Sum(int p){
		long long ret = 0;
		while (p > 0){
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}

};

int big[13], ans[13];

int main() {

	int n;
	scanf("%d", &n);

	BIT tree(n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &big[i]);
		// count big in front of i
	}

	// 1 to n
	for (int i = 1; i <= n; i++) {

		int l = 1, r = n, m;

		int p = big[i] + 1;

		while (l <= r) {
			m = (l + r) / 2;
			if (m - tree.Sum(m) >= p) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}

		if (m - tree.Sum(m) < p)m++;
		p = m;
		tree.Update(p, 1);
		ans[p] = i;

	}

	for (int i = 1; i <= n; i++)printf("%d ", ans[i]);

}