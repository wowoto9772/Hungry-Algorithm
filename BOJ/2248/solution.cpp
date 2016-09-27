#include <cstdio>

using ll = long long;

ll dp[33][33];

ll dy(int n, int m){

    ll &ret = dp[n][m];

    if(ret != -1)return ret;

    if(n == 0)return ret = 1;

    ret = dy(n-1, m);
    if(m)ret += dy(n-1, m-1);

    return ret;

}

int ans[33];
ll k;

void findAns(int n, int m){

    if(n == 0)return ;

    ll flg = dy(n-1, m);

    if(k < flg){
        ans[n] = 0;
        findAns(n-1, m);
    }else{
        ans[n] = 1;
        k -= flg;
        findAns(n-1, m-1);
    }

}

int main(){

    int n, m;
    scanf("%d %d %lld", &n, &m, &k);

    for(int i=0; i<=n; i++)for(int j=0; j<=m; j++)dp[i][j] = -1;

    k--;

    dy(n, m);

    findAns(n, m);

    for(int i=n; i>=1; i--)printf("%d", ans[i]);

}
