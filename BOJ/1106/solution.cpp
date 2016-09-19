#include <stdio.h>

#include <limits.h>

#include <algorithm>

using namespace std;

int dp[1103], p[23], a[23];

int main(){

    int c, n;
    scanf("%d %d", &c, &n);

    for(int i=1; i<=c+100; i++)dp[i] = INT_MAX;

    for(int i=1; i<=n; i++)scanf("%d %d", &p[i], &a[i]);

    int ans = INT_MAX;

    for(int i=1; i<=c+100; i++){

        for(int j=1; j<=n; j++){
            if(i-a[j] >= 0){
                if(dp[i-a[j]] == INT_MAX)continue;
                dp[i] = min(dp[i], dp[i-a[j]] + p[j]);
            }
        }

        if(i >= c)ans = min(ans, dp[i]);

    }

    printf("%d\n", ans);

}
