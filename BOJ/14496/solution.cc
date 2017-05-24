#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>

using namespace std;

int d[1003];

int main(){
	
	int a, b;
	scanf("%d %d", &a, &b);
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector < vector < int > > lnk;
	lnk.resize(n+1);
	
	for(int i=1; i<=n; i++)d[i] = INT_MAX;
	
	priority_queue < pair <int,int>, vector < pair<int,int> >, greater < pair<int,int> > > q;
	d[a] = 0;
	q.emplace(a, 0);
	
	for(int i=1; i<=m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		lnk[x].push_back(y);
		lnk[y].push_back(x);
	}
	
	while(!q.empty()){
		pair <int,int> f = q.top(); q.pop();
		if(d[f.first] < f.second)continue;
		for(auto &e : lnk[f.first]){
			if(d[e] > f.second + 1){
				d[e] = f.second + 1;
				q.emplace(e, d[e]);
			}
		}
	}
	
	if(d[b] == INT_MAX)d[b] = -1;
	printf("%d\n", d[b]);
	
}