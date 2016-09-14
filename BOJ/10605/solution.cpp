#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

vector < vector <int> > lnk;

vector <int> stk, grp;

vector <bool> vst;

int top, gtop;

void dfs(int t, int c){
	if(!t){
		if(vst[c])return ;
		vst[c] = true;
	}else{
		if(grp[c])return ;
		grp[c] = gtop;
	}

	for(int i=0; i<lnk[c].size(); i++){
		dfs(t, lnk[c][i]);
	}

	if(!t)stk[top++] = c;
}

class ele{
	public:
		int s, v;

		ele(){}
		ele(int _s, int _v){
			s = _s, v = _v;
		}
		bool operator<(const ele &A)const{
			if(v == A.v)return s < A.s;
			return v < A.v;
		}
};

int main(){

	int n, m, k;

	while(scanf("%d %d %d", &n, &m, &k) == 3){

		if(!((n|m)|k))break;

		stk.clear(), grp.clear(), vst.clear(), lnk.clear();

		stk.resize(n);
		grp.resize(n+1);
		vst.resize(n+1);
		lnk.resize(n+1);

		for(int i=1; i<=m; i++){
			int a, b;
			scanf("%d %d", &a, &b);

			lnk[a].push_back(b);
			lnk[b].push_back(a);
		}

		top = gtop = 0;

		for(int i=1; i<=n; i++)dfs(0, i);

		for(int i=top-1; i>=0; i--){
			if(grp[stk[i]])continue;
			gtop++;
			dfs(1, stk[i]);
		}

		vector < ele > dragon(n+1, {0,0});

		vector < vector <ele> > ans(n+1);

		for(int i=1; i<=k; i++){
			int ci, si, ni;
			scanf("%d %d %d", &ci, &si, &ni);
			dragon[ci].s += si;
			dragon[ci].v = max(dragon[ci].v, ni);
		}

		for(int i=1; i<=n; i++){
			if(dragon[i].s == 0)continue;
			ans[grp[i]].emplace_back(dragon[i].s, dragon[i].v);	
		}

		int ret = 0;

		for(int i=1; i<=gtop; i++){
			if(ans[i].empty())continue;
			sort(ans[i].begin(), ans[i].end());
			if(ans[i].size() == 1){
				ret += min(ans[i].back().s, ans[i].back().v+1);
			}else{

				int cur = ans[i].back().v + 1;

				int l = 1, r = cur - 1, lim;

				while(l <= r){

					lim = (l+r) >> 1;

					int tot = lim;

					for(int j=0; j<ans[i].size(); j++){
						if(ans[i][j].v + 1 <= lim)continue;
						tot -= ans[i][j].s;
					}

					if(tot >= 0){
						cur = min(cur, lim);
						r = lim - 1;
					}else{
						l = lim + 1;
					}
				}

				ret += cur;

			}
		}

		printf("%d\n", ret);

	}

}
