#include <stdio.h>

#include <queue>
#include <vector>

#include <algorithm>

using namespace std;

#define r first
#define c second

int c[103][103];

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int main(){

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for(int i=1; i<=k; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		c[x][y] = 1;
	}

	int x = 0;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(c[i][j]){
				int y = 1;
				queue < pair<int,int> > q;
				q.emplace(i, j);
				c[i][j] = 0;
				
				while(!q.empty()){
					pair<int,int> f = q.front();q.pop();
					for(int a=0; a<4; a++){
						pair<int,int> g= {f.r+dr[a], f.c+dc[a]};
						if(c[g.r][g.c]){
							c[g.r][g.c] = 0;
							y++;
							q.emplace(g);
						}
					}
				}

				x = max(x, y);
			}
		}
	}

	printf("%d\n", x);

}
