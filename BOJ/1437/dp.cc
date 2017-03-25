#include <cstdio>
#include <cmath>

using namespace std;

double dp[1000003] = {0, 0, log(2.0), log(3.0)};
int ans[1000003] = {0, 1, 2, 3,};

int main(){

    int n;
    scanf("%d", &n);

    for(int i=4; i<=n; i++){
        for(int j=2; j<=3; j++){
            if(dp[i] < dp[i-j]+log(j)){
                dp[i] = dp[i-j]+log(j);
                ans[i] = (ans[i-j]*j) % 10007;
            }
        }
    }

    printf("%d\n", ans[n]);

}
