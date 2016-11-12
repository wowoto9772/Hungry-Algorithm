#include <cstdio>

using ll = long long;
using namespace std;

ll ans[23] = {0, 1, 2};
ll dp[23][23][2];

ll dy(int lo, int hi, int big){
    if(!(lo|hi))return 1;
    ll &ret = dp[lo][hi][big];
    if(ret != -1)return ret;
    ret = 0;
    if(!big){
        for(int i=1; i<=hi; i++){
            ret += dy(lo+i-1, hi-i, 1);
        }
    }else{
        for(int i=1; i<=lo; i++){
            ret += dy(lo-i, hi+i-1, 0);
        }
    }
    return ret;
}

int main(){

    for(int n=3; n<=20; n++){
        for(int i=0; i<=n; i++)for(int j=0; j<=n; j++)for(int k=0; k<=1; k++)dp[i][j][k] = -1;    
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i > j){
                    ans[n] += dy(j-1, n-j-1, 0);
                }else if(i < j){
                    ans[n] += dy(j-2, n-j, 1);
                }
            }
        }
    }

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        printf("%lld\n", ans[n]);
    }
}
