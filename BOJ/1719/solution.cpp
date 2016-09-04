#include <stdio.h>

#include <limits.h>

#include <vector>
#include <queue>

using namespace std;

#define c first
#define a second

vector < vector < pair<int,int> > > lnk;

int d[203];
int r[203];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	lnk.resize(n+1);

	for(int i=1; i<=m; i++){

		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		lnk[x].emplace_back(z, y);
		lnk[y].emplace_back(z, x);

	}

	for(int i=1; i<=n; i++){
		
		priority_queue < pair<int,int>, vector < pair<int,int> >, greater < pair<int,int> > > q;

		for(int j=1; j<=n; j++){
			d[j] = INT_MAX;
			r[j] = 0;
		}

		d[i] = 0;
		q.emplace(0, i);

		while(!q.empty()){

			pair<int,int> f = q.top();q.pop();

			if(d[f.a] < f.c)continue;

			for(int j=0; j<lnk[f.a].size(); j++){
				
				pair<int,int> g = lnk[f.a][j];
				g.c += f.c;

				if(d[g.a] > g.c){
					d[g.a] = g.c;
					r[g.a] = f.a;
					q.emplace(g);
				}

			}

		}

		for(int j=1; j<=n; j++){
			if(i == j){
				printf("-");
			}else{
				int c = j;

				while(r[c] != i){
					c = r[c];
				}

				printf("%d", c);

			}
			printf(" ");
		}

		printf("\n");

	}

}
