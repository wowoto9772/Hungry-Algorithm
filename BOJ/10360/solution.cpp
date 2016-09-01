#include <stdio.h>
#include <limits.h>

#include <vector>

using namespace std;

class ele{
	public:
		int a, b, c;
		ele(){}
		ele(int _a, int _b, int _c){
			a = _a, b = _b, c = _c;
		}

};

int d[1003];

vector < vector <int> > lnk[2];

int stk[2003], grp[2003];

bool vst[2003];

int top, gtop;

void dfs(int t, int c){
	if(!t){
		if(vst[c])return ;
		vst[c] = true;
	}else{
		if(grp[c])return ;
		grp[c] = gtop;
	}

	for(int i=0; i<lnk[t][c].size(); i++){
		dfs(t, lnk[t][c][i]);
	}

	if(!t)stk[top++] = c;
}

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		lnk[0].clear(), lnk[1].clear();

		int n, m;
		scanf("%d %d", &n, &m);

		lnk[0].resize(n);
		lnk[1].resize(n);

		for(int i=0; i<n; i++)vst[i] = false, grp[i] = 0;

		vector < ele > _edge;

		for(int i=1; i<=m; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			_edge.emplace_back(a, b, c);
			lnk[0][a].push_back(b);
			lnk[1][b].push_back(a);
		}

		// only find 0's scc

		top = gtop = 0;

		dfs(0, 0);

		for(int i=top-1; i>=0; i--){
			if(grp[stk[i]])continue;
			gtop++;
			dfs(1, stk[i]);
		}

		vector <bool> pos(n);

		if(grp[0]){
			for(int i=0; i<n; i++){
				if(grp[0] == grp[i])pos[i] = true;
			}
		}

		for(int i=0; i<n; i++)d[i] = 0;

		bool ngt = false;

		// bellman-ford only finds that negative cycle exists

		for(int v=1; v<=n; v++){
			for(auto &edge : _edge){
				if(!pos[edge.a] || !pos[edge.b])continue;
				if(d[edge.b] > d[edge.a] + edge.c){
					d[edge.b] = d[edge.a] + edge.c;
					if(v == n)ngt = true;
				}
			}
		}

		printf("Case #%d: %s\n", ++tc, ((ngt) ? "possible" : "not possible"));

	}

}
