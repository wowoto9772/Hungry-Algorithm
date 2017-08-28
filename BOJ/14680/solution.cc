#include <cstdio>

using namespace std;
using ll = long long;

const int imod = 1000000007;

ll e[53][53], f[53][53], g[53][53];

int main(){

    int n;
    scanf("%d", &n);
    
    int p, q;
    bool flag = false;
    
    for(int x=1; x<=n; x++){
        int r, c;
        scanf("%d %d", &r, &c);
        if(x == 1){
            p = r, q = c;
            for(int i=1; i<=r; i++)for(int j=1; j<=c; j++)scanf("%lld", &e[i][j]);
            continue;
        }else{
            for(int i=1; i<=r; i++)for(int j=1; j<=c; j++)scanf("%lld", &f[i][j]);
        }
        if(q == r){
            for(int i=1; i<=p; i++){
                for(int j=1; j<=c; j++){
                    g[i][j] = 0;
                    for(int k=1; k<=q; k++){
                        g[i][j] += (e[i][k] * f[k][j]) % imod;
                        if(g[i][j] >= imod)g[i][j] -= imod;
                    }
                }
            }
            q = c;
            for(int i=1; i<=p; i++)for(int j=1; j<=q; j++)e[i][j] = g[i][j];
        }else{
            flag = true;
        }
    }
    
    int ans;
    if(flag)ans = -1;
    else{
        ans = 0;
        for(int i=1; i<=p; i++)for(int j=1; j<=q; j++){
            ans += e[i][j];
            if(ans >= imod)ans -= imod;
        }
    }
    
    printf("%d\n", ans);
}

