#include <cstdio>
#include <algorithm>

using namespace std;

int f[13] = {1,};
int dp[100003];

int main(){
    
    for(int i=1; i<=8; i++)f[i] = f[i-1] * i;
    
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        dp[i] = n;
        for(int j=1; f[j]<=i && j<=8; j++)dp[i] = min(dp[i], dp[i-f[j]] + 1);
    }
    printf("%d\n", dp[n]);

}