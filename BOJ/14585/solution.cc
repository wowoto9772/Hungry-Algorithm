#include <cstdio>
#include <algorithm>

using namespace std;

int cdy[303][303];
int dp[303][303];

int dy(int x, int y){
    if(x > 300 || y > 300)return 0;
    int &ret = dp[x][y];
    if( ret != -1 )return ret;
    ret = max(dy(x+1, y) + cdy[x+1][y], dy(x, y+1) + cdy[x][y+1]);
    return ret;
}

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        cdy[x][y] += max(0, m - (x+y));
    }
    
    for(int i=0; i<=300; i++)for(int j=0; j<=300; j++)dp[i][j] = -1;
    
    printf("%d\n", dy(0, 0) + cdy[0][0]);

}