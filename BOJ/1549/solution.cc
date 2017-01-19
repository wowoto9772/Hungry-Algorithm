#include <cstdio>
#include <limits.h>
#include <memory.h>
#include <algorithm>

using namespace std;
using ll = long long;

ll e[3003];
ll s[3003][1503];

int main(){

    int n;
    scanf("%d", &n);

    memset(s, 0xff, sizeof(s));

    for(int i=1; i<=n; i++){
        scanf("%lld", &e[i]);
        s[i][1] = e[i];
    }

    for(int i=n; i>=1; i--){
        for(int j=2; j<=n/2; j++){
            if(s[i+1][j-1] == -1)continue;
            s[i][j] = e[i] + s[i+1][j-1];
        }
    }

    ll ans = LLONG_MAX, v = -1;

    for(int k=1; k<=n/2; k++){
        for(int i=1; i<=n-k; i++){
            for(int j=i+k; j+k <= n; j++){
                ll t = s[i][k] - s[j][k];
                t = abs(t);
                if(ans >= t)ans = t, v = k;
            }
        }
    }

    printf("%lld\n%lld\n", v, ans);

}
