#include <stdio.h>
#include <vector>

#define ll long long

using namespace std;

vector < vector <int> > lnk[2];

int stk[200003], grp[200003];

bool vst[200003];

int top, gtop;

ll son;

void dfs(int t, int c){
	if(!t){
		if(vst[c])return ;
		vst[c] = true;
	}else{
		if(grp[c])return ;
		grp[c] = gtop;
		son++;
	}

	for(int i=0; i<lnk[t][c].size(); i++){
		dfs(t, lnk[t][c][i]);
	}

	if(!t)stk[top++] = c;
}

#define mod 1000000007

ll tpower[200003] = {1};

int main(){

	for(int i=1; i<=200000; i++){
		tpower[i] = tpower[i-1] * 2LL;
		tpower[i] %= mod;
	}

	int n;
	scanf("%d", &n);

	lnk[0].resize(n+1), lnk[1].resize(n+1);

	for(int i=1; i<=n; i++){
		int e;
		scanf("%d", &e);

		lnk[0][i].push_back(e);
		lnk[1][e].push_back(i);
	}

	for(int i=1; i<=n; i++){
		dfs(0, i);
	}

	long long ans = 1;

	long long tot = n;

	for(int i=top-1; i>=0; i--){
		if(grp[stk[i]])continue;
	
		gtop++;
		son = 0;

		dfs(1, stk[i]);

		if(son > 1){
			tot -= son;

			ll tmp = tpower[son];

			tmp -= 2;

			if(tmp < 0)tmp += mod;

			ans *= tmp;
			ans %= mod;
		}
	}

	ans *= tpower[tot];
	ans %= mod;

	printf("%lld\n", ans);

}
