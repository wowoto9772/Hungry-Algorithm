#include <cstdio>

using namespace std;

const int imod = 1000000000;
int dp[5005];

int main(){

    int n, k;
    scanf("%d %d", &n, &k);
    
    k--;

    for(int i=0; i<=n; i++)dp[i] = 1;

    while(k--){
        for(int i=1; i<=n; i++){
            dp[i] += dp[i-1];
            dp[i] %= imod;
        }
    }

    printf("%d\n", dp[n]);

}
