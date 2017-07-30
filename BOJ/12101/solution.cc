#include <cstdio>

using namespace std;
using ll = long long;

int n, k;
ll dp[13][3*12];

ll dy(int c, int m){
    if(m == n){
        return 1;
    }
    ll &ret = dp[c][m];
    if(ret != -1)return ret;
    ret = 0;
    for(int j=1; j<=3 && m+j <= n; j++){
        ret += dy(c+1, m+j);
    }
    return ret;
}

int main(){
    
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)for(int j=0; j<=3*12; j++)dp[i][j] = -1;
        
    ll cmp = 0;
        
    for(int i=1; i<=3; i++)cmp += dy(1, i);
    
    if(cmp < k)printf("-1");
    else{
       
        int m = 0;
        bool fst = false;
    
        for(int f=1; m < n && f<=n; f++){
            for(int i=1; i<=3 && m+i <= n; i++){
                if(k <= dy(f, m+i)){
                    m += i;
                    if(fst)printf("+");
                    else
                        fst = true;
                    printf("%d", i);
                    break;
                }else{
                    k -= dy(f, m+i);
                }
            }
        }
    }
    
}