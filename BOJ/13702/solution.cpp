#include <cstdio>

using namespace std;
using ll = long long;

int e[1000003];

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    ll l = 0, r = 9999999999999999, m;

    ll ans = 0;

    while (l <= r){
        m = (l+r) / 2;
        ll c = 0;
        for(int i=1; i<=n; i++){
            c += e[i] / m;
        }
        if(c >= k)ans = m, l = m + 1;
        else{
            r = m - 1;
        }
    }

    printf("%lld\n", ans);

}
