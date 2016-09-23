#include <stdio.h>

using ll = long long;

ll dp[33][63];

ll dy(int f, int h){

    if(f == 0 && h == 0)return 1LL;

    ll &ret = dp[f][h];

    if(ret != -1)return ret;

    ret = 0;

    if(f)ret += dy(f-1, h+1);
    if(h)ret += dy(f, h-1);

    return ret;

}

int main(){

    int f;

    while(scanf("%d", &f) == 1 && f){

        for(int i=0; i<=f; i++){
            for(int j=0; j<=2*f; j++){
                dp[i][j] = -1;
            }
        }

        printf("%lld\n", dy(f, 0));

    }

}
