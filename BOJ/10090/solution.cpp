#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class BIT{
	public:
		vector <int> T;
		int S;

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

int e[1000003];

int main(){

	int n;
	scanf("%d", &n);

	BIT tree(n);

	for(int i=1; i<=n; i++){

		scanf("%d", &e[i]);

		tree.Update(e[i], 1);
	}

	long long ans = 0;

	for(int i=1; i<=n; i++){
		tree.Update(e[i], -1);
		ans += tree.Sum(e[i]);
	}

	printf("%lld\n", ans);

}
