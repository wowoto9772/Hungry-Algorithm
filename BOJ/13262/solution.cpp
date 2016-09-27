#include <cstdio>

#include <limits.h>

#include <vector>

#include <algorithm>

using namespace std;

using ll = long long;

int res[5003][5003];
int e[5003];

ll dp[5003][5003];

int p[5003][32];

int bitSize(int v){

    int ret = 0;

    while(v){
        ret += v&1;
        v >>= 1;
    }

    return ret;

}

int n, k;

ll dy(int m, int l){

    if(l == k-1)return res[m][n];

    ll &ret = dp[m][l];

    if( ret != -1 )return ret;

    ret = 0;

    for(int i=0; i<=31; i++){

        int o = p[m][i];
        if(o){

            ret = max(ret, res[m][o] + dy(o+1, l+1));

        }
    }

    return ret;

}

int main(){

    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
    }

    for(int i=1; i<=n; i++){

        p[i][bitSize(e[i])] = i;
        res[i][i] = e[i];

        int v = e[i];
        for(int j=i+1; j<=n; j++){
            v |= e[j];
            if(p[i][bitSize(v)] == 0){
                p[i][bitSize(v)] = j;
            }

            res[i][j] = res[i][j-1] | e[j];
      
        }

        for(int j=0; j<=k; j++)dp[i][j] = -1;

    }

    printf("%lld\n", dy(1, 0));

}
