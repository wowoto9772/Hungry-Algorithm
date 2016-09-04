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

			if(p == 0)return 0LL;

			long long ret = 0;
			while (p > 0){
				ret += T[p];
				p -= p & (-p);
			}return ret;
		}
};

#define ll long long

vector < vector <int> > color;
vector < vector <ll> > csum;

int c[200003], s[200003];

int main(){

	BIT tree(2000);

	int n;
	scanf("%d", &n);

	color.resize(n+1);

	for(int i=1; i<=n; i++){

		scanf("%d %d", &c[i], &s[i]);

		tree.Update(s[i], s[i]);

		color[c[i]].push_back(s[i]);

	}

	csum.resize(n+1);

	for(int i=1; i<=n; i++){
		sort(color[i].begin(), color[i].end());
		csum[i].resize(color[i].size());
		for(int j=0; j<color[i].size(); j++){
			if(j == 0)csum[i][j] = color[i][j];
			else{
				csum[i][j] = csum[i][j-1] + color[i][j];
			}
		}
	}


	for(int i=1; i<=n; i++){

		ll ans = tree.Sum(s[i]-1);

		int p = lower_bound(color[c[i]].begin(), color[c[i]].end(), s[i]) - color[c[i]].begin();

		if(p){
			ans -= csum[c[i]][p-1];
		}

		printf("%lld\n", ans);

	}

}
