#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>

using ll = long long;
using namespace std;

int p[10003], c[10003];
vector < vector <int> > lnk;
ll dp[10003][2];

ll dy(int v, int i){
    ll &ret = dp[v][i];
    if(ret != -1)return ret;
    ret = 0;
    for(auto &e : lnk[v]){
        if(p[v] == e)continue;
        p[e] = v;
        if(i == 1){
            ret += dy(e,0);
        }else{
            ret += max(dy(e,0), c[e] + dy(e,1));
        }
    }
    return ret;
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

    memset(dp, 0xff, sizeof(dp));

    printf("%lld\n", max(dy(1,0), c[1] + dy(1,1)));

}
