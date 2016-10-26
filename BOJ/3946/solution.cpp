#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

double dp[1003][1003]; 
// dp[n][d] : nth, distance d
// dp[n][d] = L(dp[n-1][d+1])+M(dp[n-1][d])+R(dp[n-1,d-1])

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        double pl, pr, ps; // probability (left, right, stop)
        scanf("%d %lf %lf", &n, &pl, &pr);

        ps = 1.0 - pl - pr;

        for(int i=0; i<=n+1; i++)for(int j=0; j<=n+1; j++){
            dp[i][j] = 0.0;
        }

        for(int i=1; i<=n; i++){
            for(int j=0; j<=i; j++){
                dp[i][j] = pl * dp[i-1][j+1] + ps * dp[i-1][j];
                if(j > 0)dp[i][j] += pr * dp[i-1][j-1];
                else
                    dp[i][j] += pr * (dp[i-1][0] + 1.0);
            }
        }

        printf("%.4lf\n", dp[n][0]);

    }

}
