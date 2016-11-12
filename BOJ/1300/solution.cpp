#include <cstdio>
#include <algorithm>

using ll = long long;
using namespace std;

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    ll l = 1, r = k, m;
    ll ans;

    while( l <= r ){
        m = (l+r) / 2;

        ll c = 0;
        for(int i=1; i<=n; i++){
            c += min(n, (int)m/i);
        }

        if(c >= k){
            r = m - 1;
            ans = m;
        }else{
            l = m + 1;
        }
    }

    printf("%lld\n", ans);

}
