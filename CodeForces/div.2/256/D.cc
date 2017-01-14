#include <cstdio>
#include <algorithm>

using namespace std;

using ll = long long;

int main(){

    ll n, m;
    ll k;
    scanf("%lld %lld %lld", &n, &m, &k);

    ll l = 1, r = n*m, mid;
    ll ans;
    while( l <= r ){
        mid = (l+r) / 2;
        ll cmp = 0;
        for(int i=1; i<=n; i++){
            cmp += min(mid / i, (ll) m);
        }

        if(cmp >= k){
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }

    printf("%lld\n", ans);

}
