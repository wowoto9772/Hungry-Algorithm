#include <cstdio>

using namespace std;
using ll = long long;

const ll lmod = 1000000007LL;

ll c, v;
int l;
ll dp[2][503];

ll dy(int iv, int n){
    
    if(n == l){
        return iv == 1;
    }
    ll &ret = dp[iv][n];
    if(ret != -1)return ret;
    ret = (v * dy(1, n+1)) % lmod;
    if(iv == 1)ret += (c * dy(0, n+1)) % lmod;
    return ret %= lmod;
}
    
int main(){
    
    int t;
    scanf("%d", &t);
    
    int tc = 0;
    
    while(t--){
        scanf("%lld %lld %d", &c, &v, &l);
        for(int i=0; i<l; i++)dp[0][i] = dp[1][i] = -1;
        printf("Case #%d: %lld\n", ++tc, dy(1, 0));
    }

}