#include <cstdio>

using ll = long long;
using namespace std;
const ll lmod = 1000000007LL;

ll c[2050][2050], dp[2050] = {1};

int main(){

    int n;
    scanf("%d", &n);

    c[0][0] = 1;
    for(int i=1; i<=(1<<(n+1))-2; i++){
        c[i][0] = 1;
        for(int j=1; j<=i; j++){
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % lmod;
        }
    }

    for(int i=1; i<=n; i++){
        dp[i] = (((dp[i-1] * dp[i-1]) % lmod) * c[(1<<(i+1))-2][(1<<i)-1]) % lmod;
    }

    printf("%lld\n", dp[n]);

}
