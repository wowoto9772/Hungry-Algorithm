#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;
using ll = long long;

ll dp[1003][1003][2];
int x[2][1003], y[2][1003];
int h, g;

ll dy(int a, int b, int c){
    
    if(a == h){
        if(b < g)return (1LL<<40);
        else
            return 0;
    }
    
    ll &ret = dp[a][b][c];
    if(ret != -1)return ret;
    ret = (1LL<<40);
    ll p, q;
    if(a < h){
        if(c == 0){
            p = (x[0][a] - x[0][a+1]), q = (y[0][a] - y[0][a+1]);
        }else{
            p = (x[1][b] - x[0][a+1]), q = (y[1][b] - y[0][a+1]);
        }
        ret = min(ret, dy(a+1, b, 0) + p*p+q*q);
    }
    if(b < g){
        if(c == 0){
            p = (x[0][a] - x[1][b+1]), q = (y[0][a] - y[1][b+1]);
        }else{
            p = (x[1][b] - x[1][b+1]), q = (y[1][b] - y[1][b+1]);
        }
        ret = min(ret, dy(a, b+1, 1) + p*p+q*q);
    }
    return ret;
    
}

int main(){
    
    scanf("%d %d", &h, &g);
    
    for(int i=1; i<=h; i++)scanf("%d %d", &x[0][i], &y[0][i]);
    for(int i=1; i<=g; i++)scanf("%d %d", &x[1][i], &y[1][i]);
    
    for(int i=0; i<=h; i++)for(int j=0; j<=g; j++)dp[i][j][0] = dp[i][j][1] = -1;
    
    printf("%lld\n", dy(1, 0, 0));

}