#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>

using ll = long long;
using namespace std;

int c[10003], p[10003];
vector < vector <int> > lnk;
ll dp[10003][2];

void dy(int v){
    dp[v][1] = c[v];
    for(auto &e : lnk[v]){
        if(p[v] == e)continue;
        p[e] = v;
        dy(e);
        dp[v][0] += max(dp[e][0], dp[e][1]);
        dp[v][1] += dp[e][0];
    }
}

int main(){

    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)scanf("%d", &c[i]);

    lnk.resize(n+1);

    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    dy(1);
    printf("%lld\n", max(dp[1][0], dp[1][1]));

}
