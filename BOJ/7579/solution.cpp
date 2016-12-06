#include <cstdio>

using namespace std;

int dp[10003], m[103], c[103];

int main(){

    int n, r;
    scanf("%d %d", &n, &r);

    int e = 0;

    for(int i=1; i<=n; i++)scanf("%d", &m[i]);
    for(int i=1; i<=n; i++){
        scanf("%d", &c[i]);
        e += c[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=e-c[i]; j>=0; j--){
            if(dp[j+c[i]] < dp[j]+m[i]){
                dp[j+c[i]] = dp[j]+m[i];
            }
        }
    }

    for(int i=0; i<=e; i++){
        if(dp[i] >= r){
            printf("%d\n", i);
            return 0;
        }
    }

}
