#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int n;
int dp[1<<15][15][10];
int c[17][17];

int dy(int s, int x, int p){
    int &ret = dp[s][x][p];
    if(ret != -1)return ret;
    ret = 0;
    for(int i=1; i<n; i++){
        if(s&(1<<i))continue;
        if(p <= c[x][i]){
            ret = max(ret, 1+dy(s|(1<<i), i, c[x][i]));
        }
    }
    return ret;
}

int main(){
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)scanf("%1d", &c[i][j]);
    memset(dp, 0xff, sizeof(dp));
    
    printf("%d\n", 1 + dy(1, 0, 0));
    
}
