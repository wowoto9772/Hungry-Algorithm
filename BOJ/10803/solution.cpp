#include <cstdio>
#include <algorithm>

using namespace std;

int dp[10003][103];

int dy(int w, int h){

    if(w == h)return 1;

    if(w < h)swap(w, h);

    int &ret = dp[w][h];

    if( ret != -1 )return ret;

    ret = w * h;

    for(int i=h; i >= 1; i--){
        ret = min(ret, dy(w-i, h) + dy(i, h));
        ret = min(ret, dy(w, i) + dy(w, h-i));
    }

    return ret;

}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    if(n < m)swap(n, m);

    for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)dp[i][j] = -1;

    for(int i=1; i<=m; i++)dp[i][i] = 1;

    printf("%d\n", dy(n, m));

}
