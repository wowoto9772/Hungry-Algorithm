#include <stdio.h>

#include <vector>
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
			if(p <= 0)return 0;
			long long ret = 0;
			while (p > 0){
				ret += T[p];
				p -= p & (-p);
			}return ret;
		}
};

int l[20003];

int main(){

	int n, s;
	scanf("%d %d", &n, &s);

	BIT tree(1000003);

	for(int i=1; i<=n; i++){
		scanf("%d", &l[i]);

		tree.Update(l[i], 1);
	}

	long long ans = 0;

	for(int i=1; i<=n; i++){
		tree.Update(l[i], -1);
		ans += tree.Sum(s - l[i]);
	}

	printf("%lld\n", ans);

}
