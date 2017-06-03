#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;
using ll = long long;

ll dp[103][103];
int n, k;
int x[103], y[103];

ll dy(int d, int c){
    if(d == 0)return 0;
    else if(c == n)return INT_MAX;
    ll &ret = dp[d][c];
    if(ret != -1)return ret;
    ret = INT_MAX;
    for(int i=d/y[c]; i>=1; i--){
        ret = min(ret, dy(d-i*y[c], c+1) + x[c]*i + i*(i-1)/2*k);
    }
    ret = min(ret, dy(d, c+1));
    return ret;
}

int main(){

    int m;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<n; i++){
        scanf("%d %d", &x[i], &y[i]);
    }

    for(int i=0; i<=m; i++)for(int j=0; j<n; j++)dp[i][j] = -1;

    printf("%lld\n", dy(m, 0));

}
