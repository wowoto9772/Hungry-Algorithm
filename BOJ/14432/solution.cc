#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll ans = 0;

vector < vector < int > > lnk;

bool chk[100003];
int w[100003];

void dfs(int c){

    int v = 0;
    for(auto &e : lnk[c]){
        if(chk[e])continue;
        chk[e] = true;
        dfs(e);
        v = max(v, w[e]);
    }

    w[c] -= v;
    for(auto &e : lnk[c]){
        w[e] -= v;
    }
    ans += v;
    
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)scanf("%d", &w[i]);
    lnk.resize(n+1);

    for(int i=1; i<=m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        lnk[x].push_back(y);
        lnk[y].push_back(x);
    }

    dfs(1);

    printf("%lld\n", ans);

}
