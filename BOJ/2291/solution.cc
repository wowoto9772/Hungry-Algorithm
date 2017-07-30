#include <cstdio>

using namespace std;
using ll = long long;

int n, k;
ll dp[13][223][223];

ll dy(int c, int l, int m){
    if(c == n){
        return m == 0;
    }
    ll &ret = dp[c][l][m];
    if(ret != -1)return ret;
    ret = 0;
    for(int j=l; j<=m; j++){
        ret += dy(c+1, j, m-j);
    }
    return ret;
}

int main(){
    
    int m;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++)for(int j=0; j<=m; j++)for(int k=0; k<=m; k++)dp[i][j][k] = -1;
        
    for(int i=1; i<=m; i++)dy(1, i, m-i);
    
    int l = 1, f = 1;
    while(f <= n){
        for(int i=l; i<=m; i++){
            l = i;
            if(k <= dy(f, i, m-i)){
                m -= i;
                printf("%d ", i);
                break;
            }else{
                k -= dy(f, i, m-i);
            }
        }
        f++;
    }

}