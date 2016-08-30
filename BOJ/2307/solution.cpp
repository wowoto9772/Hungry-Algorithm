#include <stdio.h>

#include <limits.h>

#include <vector>
#include <queue>

using namespace std;

#define c first
#define a second

vector < vector < pair<int,int> > > lnk;
vector < pair<int,int> > edge;

int d[1003];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	lnk.resize(n+1);

	for(int i=1; i<=m; i++){
		
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		lnk[a].emplace_back(c, b);
		lnk[b].emplace_back(c, a);

		edge.emplace_back(min(a,b), max(a,b));

	}

	int ans = 0;

	for(int i=0; i<edge.size() && ans < INT_MAX; i++){
		

		int aa = edge[i].first, bb = edge[i].second;

		priority_queue < pair<int,int>, vector < pair<int,int> >, greater < pair<int,int> > > q;

		q.emplace(0, 1);

		for(int j=2; j<=n; j++)d[j] = INT_MAX;

		while(!q.empty()){
			
			pair<int,int> f = q.top();q.pop();

			if(d[f.a] < f.c)continue;

			for(int j=0; j<lnk[f.a].size(); j++){
				
				pair<int,int> g = {lnk[f.a][j].c + f.c, lnk[f.a][j].a};

				if(min(f.a, g.a) == aa && max(f.a, g.a) == bb)continue;

				if(d[g.a] > g.c){

					d[g.a] = g.c;

					q.emplace(g);

				}

			}

		}

		//printf("%d %d = %d\n", aa, bb, d[n]);

		ans = max(ans, d[n]);

	}

	if(ans == INT_MAX)ans = -1;
	else{
		
		priority_queue < pair<int,int>, vector < pair<int,int> >, greater < pair<int,int> > > q;

		for(int i=2; i<=n; i++)d[i] = INT_MAX;

		q.emplace(0, 1);

		while(!q.empty()){
			
			pair<int,int> f = q.top();q.pop();

			if(d[f.a] < f.c)continue;

			for(int j=0; j<lnk[f.a].size(); j++){
				
				pair<int,int> g = {lnk[f.a][j].c + f.c, lnk[f.a][j].a};

				if(d[g.a] > g.c){

					d[g.a] = g.c;

					q.emplace(g);

				}

			}

		}

		if(ans != INT_MAX){

			ans = ans - d[n];

		}

	}
	
	printf("%d\n", ans);

}
