#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct kosaraju{

    vector < vector <int> > lnk[2];
    vector <int> stk, grp;
    vector <bool> vst;
    int n, top, gtop;

    vector < vector <int> > G;

    kosaraju(int _n):n(_n), stk(_n), grp(_n+1), vst(_n+1), top(0), gtop(0){
        lnk[0].resize(n+1);
        lnk[1].resize(n+1);
    }

    void addEdge(int a, int b){
        lnk[0][a].push_back(b);
        lnk[1][b].push_back(a);
    }

    void dfs(int t, int c){
        if(!t){
            if(vst[c]) return ;
            vst[c] = true;
        }else{
            if(grp[c]) return ;
            grp[c] = gtop;
        }
        for(int i=0; i<lnk[t][c].size(); i++){
            dfs(t, lnk[t][c][i]);
        }
        if(!t)stk[top++] = c;
    }

    void solve(){
        for(int i=1; i<=n; i++)dfs(0, i);
        for(int i=top-1; i>=0; i--){
            if(grp[stk[i]])continue;
            gtop++;
            dfs(1, stk[i]);
        }
    }

};

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    kosaraju scc(n);

    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        scc.addEdge(a, b);
    }

    scc.solve();

    vector <int> g(scc.gtop+1);

    for(int i=1; i<=n; i++){
        g[scc.grp[i]]++;
    }

    int ans = 0;
    for(int i=0; i<g.size(); i++){
        ans = max(ans, g[i]);
    }

    printf("%d\n", ans);

}
