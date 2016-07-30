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

int main() {

	int n;
	scanf("%d", &n);

	BIT tree(n);

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		tree.Update(i, a);
	}

	int q;
	scanf("%d", &q);

	for (int i = 1; i <= q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%lld\n", tree.Sum(b) - tree.Sum(a - 1));
	}

}