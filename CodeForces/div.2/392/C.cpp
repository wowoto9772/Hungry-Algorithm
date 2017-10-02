#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

ll c[103][103];

int main(){
    
    int n, m, x, y;
    ll k;
    scanf("%d %d %lld %d %d", &n, &m, &k, &x, &y);
    
    int cyc = max(2*n-2, 1) * m;
    ll w = k / cyc;
    
    for(int i=1; i<=n; i++)for(int j=1; j<=m; j++){
        if(i == 1 || i == n)c[i][j] = w;
        else
            c[i][j] = (w<<1);
    }
    
    ll r = k % cyc;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m && r > 0; j++){
            c[i][j]++;
            r--;
        }
    }
    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=m && r > 0; j++){
            c[i][j]++;
            r--;
        }
    }
    
    ll p = 0, q = (1LL<<62);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(p < c[i][j])p = c[i][j];
            if(q > c[i][j])q = c[i][j];
        }
    }
    
    printf("%lld %lld %lld\n", p, q, c[x][y]);

}