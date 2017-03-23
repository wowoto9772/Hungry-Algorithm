#include <cstdio>
#include <memory.h>

using namespace std;

using ll = long long;

ll dp[93] = {1, 1,};

int main(){

    ll k;
    scanf("%lld", &k);

    for(int i=2; i<=90; i++)dp[i] = dp[i-1] + dp[i-2];

    bool zero = false;

    for(int i=89; i>=1; i--){
        if(dp[i] <= k && k < dp[i+1]){
            printf("1");
            zero = true;
            k -= dp[i];
        }else{
            if(zero)printf("0");
        }
    }

}
