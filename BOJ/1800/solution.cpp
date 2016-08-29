#include <stdio.h>
#include <limits.h>

#include <queue>
#include <vector>

#include <functional>

using namespace std;

#define c first
#define a second

int n, k;

int d[1003];

vector < vector < pair<int, int> > > lnk;

bool bfs(int lim){

	priority_queue < pair <int,int> , vector < pair <int,int> >, greater < pair <int,int> > > q;

	for(int i=2; i<=n; i++)d[i] = INT_MAX;

	q.emplace(0, 1);

	while(!q.empty()){

		pair <int,int> f = q.top();q.pop();

		if(d[f.a] < f.c)continue;

		for(int i=0; i<lnk[f.a].size(); i++){
			pair <int,int> g = {f.c + (lnk[f.a][i].c > lim), lnk[f.a][i].a};
			if(d[g.a] > g.c){
				d[g.a] = g.c;
				q.emplace(g);
			}
		}

	}

	return d[n] <= k;

}

class ele{
	public:
		int a, k, cc;
		ele(){}
		ele(int _a, int _k, int _cc){
			a = _a, k = _k, cc = _cc;
		}

		bool operator<(const ele &A)const{
			return cc > A.cc;
		}

};

int di[1003][1003];

int main(){

	int p;
	scanf("%d %d %d", &n, &p, &k);

	lnk.resize(n+1);

	for(int i=1; i<=p; i++){

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		lnk[a].emplace_back(c, b);
		lnk[b].emplace_back(c, a);

	}

	if(bfs(INT_MAX)){

		int l = 0, r = 1000003, m;

		int lim = r;

		while(l <= r){
			m = (l+r) / 2;
			if(bfs(m)){
				lim = min(lim, m);
				r = m - 1;
			}else{
				l = m + 1;
			}
		}

		for(int i=1; i<=n; i++){
			for(int j=0; j<=k; j++){
				di[i][j] = INT_MAX;
			}
		}

		di[1][k] = 0;

		priority_queue < ele > q;
		q.emplace(1, k, 0);

		while(!q.empty()){

			ele f = q.top();q.pop();

			if(di[f.a][f.k] < f.cc)continue;

			for(int i=0; i<lnk[f.a].size(); i++){

				if(lnk[f.a][i].c <= lim){
					ele g = {lnk[f.a][i].a, f.k, max(lnk[f.a][i].c, f.cc)};
					if(di[g.a][g.k] > g.cc){
						di[g.a][g.k] = g.cc;
						q.emplace(g);
					}
				}else if(f.k){
					ele g = {lnk[f.a][i].a, f.k-1, f.cc};
					if(di[g.a][g.k] > g.cc){
						di[g.a][g.k] = g.cc;
						q.emplace(g);
					}
				}

			}
		}

		int ans = INT_MAX;
		for(int i=0; i<=k; i++){
			ans = min(ans, di[n][i]);
		}

		printf("%d\n", ans);

	}else{
		printf("-1");
	}

}
