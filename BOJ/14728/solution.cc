#include <cstdio>

using namespace std;

int dp[10003];

int main(){
    
    int n, t;
    scanf("%d %d", &n, &t);
    
    while(n--){
        int p, q;
        scanf("%d %d", &p, &q);
        for(int i=t-p; i>=0; i--){
            if(dp[i+p] < dp[i]+q){
                dp[i+p] = dp[i]+q;
            }
        }
    }
    
    int ans = 0;
    for(int i=1; i<=t; i++)if(ans < dp[i])ans = dp[i];
    printf("%d\n", ans);

}