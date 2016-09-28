#include <cstdio>
#include <vector>

using namespace std;

// Articulation Point, 1-based
// adj : adjcent list
// AP(int N) : N is vertex number
// cut[i] : true if i th vertex = AP
struct AP {
    vector<vector<int>> adj;
    vector<int> low, dfn, parent;
    vector<bool> c, cut;
    int cnt, n;
    AP(int N) : n(N), adj(N+1, vector<int>()), low(N+1, 0), dfn(N+1, 0), 
                parent(N+1, 0), c(N+1, false), cut(N+1, false),
                cnt(0) {}
    void dfs(int x) {
        int children = 0;
        c[x] = true;
        dfn[x] = ++cnt;
        low[x] = cnt;
        for (int i = 0; i < adj[x].size(); i++) {
            int y = adj[x][i];
            if (c[y] == false) {
                children ++;
                parent[y] = x;
                dfs(y);
                low[x] = min(low[x], low[y]);
                if (!parent[x] && children >= 2) cut[x] = true;
                if (parent[x] && low[y] >= dfn[x]) cut[x] = true;
            } else if (y != parent[x]) low[x] = min(low[x], dfn[y]);
        }
    }
    void solve() {
        for(int i=1; i<=n; ++i) {
            if(!c[i]) dfs(i);
        }
    }
};

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    AP ap(n);

    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        ap.adj[a].push_back(b);
        ap.adj[b].push_back(a);
    }

    ap.solve();

    int r = 0;

    for(int i=1; i<=n; i++){
        if(ap.cut[i])r++;
    }

    printf("%d\n", r);

    for(int i=1; i<=n; i++){
        if(ap.cut[i])printf("%d ", i);
    }

}
