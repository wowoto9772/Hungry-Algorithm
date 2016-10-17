#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1003][1003];

int dy(int w, int h){
    
    if(w == 0 || h == 0)return 0;

    if(w > h)swap(w, h);

    int &ret = dp[w][h];

    if( ret != -1 )return ret;

    ret = w * h;

    int l = min(w,h);

    for(int i=l; i >= 1; i--){
        ret = min(ret, 1 + dy(w-i, h) + dy(i, h-i)); 
        ret = min(ret, 1 + dy(w, h-i) + dy(w-i, i));
    }                    

    return ret;

}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    if(n > m)swap(n, m);

    for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)dp[i][j] = -1;

    for(int i=1; i<=m; i++)dp[i][i] = 1;

    printf("%d\n", dy(n, m));

}
