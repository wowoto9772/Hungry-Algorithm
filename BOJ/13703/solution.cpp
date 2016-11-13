#include <cstdio>
#include <memory.h>

using namespace std;
using ll = long long;

ll dp[65][133];

ll dy(int n, int k){

    if(n == 0)return 1LL;
    ll &ret = dp[n][k];
    if(ret != -1)return ret;
    ret = 0;
    ret += dy(n-1, k+1);
    if(k > 1)ret += dy(n-1, k-1);
    return ret;
}

int main(){

    int n, k;
    scanf("%d %d", &k, &n);

    memset(dp, 0xff, sizeof(dp));

    printf("%lld\n", dy(n, k));

}
