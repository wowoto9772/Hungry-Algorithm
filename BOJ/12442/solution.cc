#include <cstdio>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;

int s[103];
ll t[103], d[103][10003];

int main(){
	
	int tcs;
	scanf("%d", &tcs);
	
	int tc = 0;
	while(tcs--){
		int n, p, m;
		scanf("%d %d %d", &n, &p, &m);
		
		for(int i=1; i<=p; i++){
			scanf("%d %lld", &s[i], &t[i]);
		}
		
		for(int i=1; i<=p; i++)for(int j=1; j<=n; j++)d[i][j] = (1LL<<31);
		
		vector < vector < pair <int,int> > > lnk;
		lnk.resize(n+1);
		
		for(int i=1; i<=m; i++){
			int d, l;
			scanf("%d %d", &d, &l);
			
			int x;
			for(int j=1; j<=l; j++){
				int y;
				scanf("%d", &y);
				if(j >= 2){
					lnk[x].emplace_back(y, d);
					lnk[y].emplace_back(x, d);
				}
				x = y;
			}
		}
		
		priority_queue < pair <ll,ll>, vector < pair<ll,ll> >, greater < pair<ll,ll> > > q;
		
		for(int i=1; i<=p; i++){
			d[i][s[i]] = 0;
			q.emplace(s[i], 0);
			
			while(!q.empty()){
				pair <ll,ll> f = q.top(); q.pop();
				if(d[i][f.first] < f.second)continue;
				for(auto &e : lnk[f.first]){
					ll cst = f.second + e.second * t[i];
					if(d[i][e.first] > cst){
						d[i][e.first] = cst;
						q.emplace(e.first, cst);
					}
				}
			}
		}
		
		ll ans = (1LL<<31);
		
		for(int i=1; i<=n; i++){
			ll tmp = 0;
			for(int j=1; j<=p; j++){
				tmp = max(tmp, d[j][i]);
			}
			if(ans > tmp)ans = tmp;
		}
		
		if(ans == (1LL<<31))ans = -1;
		printf("Case #%d: %lld\n", ++tc, ans);
		
	}
	
}