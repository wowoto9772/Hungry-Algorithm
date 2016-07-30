#include <stdio.h>
#include <vector>
#define ll long long

using namespace std;

class BIT{
public:
	vector <ll> T;
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

	int n, q;
	scanf("%d %d", &n, &q);

	BIT tree(n + 1);

	for (int i = 1; i <= q; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a & 1) {
			tree.Update(b, c);
		}
		else {
			printf("%lld\n", tree.Sum(c) - tree.Sum(b - 1));
		}
	}

}