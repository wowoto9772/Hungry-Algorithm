#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define NMAX 100003

vector < vector <int> > a;
bool c[NMAX];
int low[NMAX];
int dfn[NMAX];
int parent[NMAX];
int cnt;

bool cut[NMAX];
map <int, map<int, bool> > bridge;

void dfs(int x) {

	c[x] = true;
	dfn[x] = ++cnt;
	low[x] = cnt;

	int children = 0;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (!c[y]) {
			children += 1;
			parent[y] = x;
			dfs(y);
			low[x] = min(low[x], low[y]);
            
			if (!parent[x] && children >= 2) {
				cut[x] = true;
			}
            
			if (parent[x] && low[y] >= dfn[x]) {
				cut[x] = true;
			}
            
			if (low[y] > dfn[x]) {
			    bridge[min(x,y)][max(x,y)] = true;
			}
		}
		else if (y != parent[x]) {
			low[x] = min(low[x], dfn[y]);
		}
	}
}

vector < pair <int,int> > edge;

int main() {

	int n;
	scanf("%d", &n);
    
    a.resize(n+1);

	for(int i=1; i<n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
        
        edge.emplace_back(min(u,v), max(u,v));

		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (c[i] == false) {
			dfs(i);
		}
	}
    
    int q;
    scanf("%d", &q);
    
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 1){
            printf("%s\n", cut[b] ? "yes" : "no");
        }else{
            --b;
            printf("%s\n", bridge[edge[b].first][edge[b].second] ? "yes" : "no");
        }
    }

	return 0;

}