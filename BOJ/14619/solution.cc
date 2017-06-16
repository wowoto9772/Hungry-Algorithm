#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int h[103];
bool lnk[103][103];
int dp[103][503];

int dy(int i, int k){
    if(k == 0)return h[i];
    int &ret = dp[i][k];
    if(ret != -1)return ret;
    ret = 10001;
    for(int j=1; j<=n; j++){
        if(lnk[i][j]){
            ret = min(ret, dy(j, k-1));
        }
    }
    return ret;
}

int main(){
    
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)scanf("%d", &h[i]);
    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        lnk[a][b] = lnk[b][a] = true;
    }
    
    for(int i=1; i<=n; i++)for(int j=1; j<=500; j++)dp[i][j] = -1;
        
    int q;
    scanf("%d", &q);
    
    while(q--){
        int v, k;
        scanf("%d %d", &v, &k);
        int d = dy(v, k);
        if(d == 10001)d = -1;
        printf("%d\n", d);
    }

}