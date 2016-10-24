#include <cstdio>

using ll = long long;
using namespace std;

const ll lmod = 1000000007LL;

ll dp[503][4503];

int main(){

    for(int i=0; i<10; i++)dp[1][i] = 1;

    for(int i=1; i<=499; i++){
        for(int j=0; j<=i*9; j++){
            for(int k=0; k<10; k++){
                dp[i+1][j+k] += dp[i][j];
                dp[i+1][j+k] %= lmod;
            }
        }
    }

    int t;
    scanf("%d", &t);

    int tc = 0;

    while(t--){

        int n;
        scanf("%d", &n);

        ll ans = 0;

        for(int i=0; i<=n*9; i++){
            ans += (dp[n][i] * dp[n][i]) % lmod;
            ans %= lmod;
        }

        printf("Case #%d: %lld\n", ++tc, ans);

    }

}
