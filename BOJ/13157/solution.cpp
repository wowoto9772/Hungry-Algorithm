#include <stdio.h>
#include <limits.h>

#include <functional>

#include <vector>
#include <queue>

#include <algorithm>

using namespace std;


vector < vector <int> > lnk;

class ele{
public:
	int p, a, c;
	ele(){}
	ele(int _p, int _a, int _c){
		p = _p, a = _a, c = _c;
	}

	bool operator<(const ele &A)const{
		return c > A.c;
	}

};

int d[103][103];

bool cant[103][103][103]; // a, b, c a->b->c cannot

int c[103];

int main(){

	int n;
	scanf("%d", &n);

	lnk.resize(n+1);

	for(int i=1; i<=n; i++){
		
		int m, t;
		scanf("%d %d", &m, &t);

		c[i] = t;

		for(int j=1; j<=m; j++){
			
			int s, x;
			scanf("%d %d", &s, &x);

			lnk[i].push_back(x);

			for(int k=1; k<=s; k++){
				int y;
				scanf("%d", &y);

				cant[y][i][x] = true;
			}

		}

	}

	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			d[i][j] = INT_MAX;
		}
	}

	priority_queue < ele > q;

	q.emplace(0, 1, c[1]);

	d[0][1] = c[1];

	while(!q.empty()){
		ele f = q.top(); q.pop();
		if(d[f.p][f.a] < f.c)continue;
		for(int i=0; i<lnk[f.a].size(); i++){
			int _g = lnk[f.a][i];
			ele g = {f.a, _g, f.c+c[_g]};
			if(cant[f.p][g.p][g.a])continue;
			if(d[g.p][g.a] > g.c){
				d[g.p][g.a] = g.c;
				q.emplace(g);
			}
		}
	}

	int ans = INT_MAX;

	for(int i=0; i<n; i++){
		ans = min(ans, d[i][n]);
	}

	if(ans == INT_MAX)printf("impossible\n");
	else{
		printf("%d\n", ans);
	}

}
