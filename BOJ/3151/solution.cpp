#include <cstdio>

using ll = long long;
using namespace std;

int e[10003];
ll dp[40004];

int main(){

    int n;
    scanf("%d", &n);

    int mid = 20000;

    long long ans = 0;

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        for(int j=1; j<i-1; j++){
            dp[mid+e[j]+e[i-1]]++;
        }
        ans += dp[mid-e[i]];
    }
    printf("%lld\n", ans);

}
