#include <cstdio>

using ll = long long;

using namespace std;

ll dp[83], f[83] = {1,1,};

int main(){

    int n;
    scanf("%d", &n);

    for(int i=2; i<=n; i++)f[i] = f[i-1] + f[i-2];

    for(int i=5; i<=n; i++)dp[i] = (f[i-1]+f[i-2])*2LL+f[i-1]*2LL;

    dp[1] = 4, dp[2] = 6, dp[3] = 10, dp[4] = 16;

    printf("%lld\n", dp[n]);

}
