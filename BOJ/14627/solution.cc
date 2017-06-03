#include <cstdio>

using namespace std;
using ll = long long;

int e[1000003];

int main(){

    int s, c;
    scanf("%d %d", &s, &c);

    ll tot = 0;

    for(int i=0; i<s; i++){
        scanf("%d", &e[i]);
    }

    ll x = 0;

    int l=1, r=1000000000, m;
    while(l <= r){
        m = (l+r) >> 1;

        ll d = 0;

        for(int i=0; i<s; i++){
            d += e[i] / m;
        }

        if(d < c)r = m - 1;
        else{
            l = m + 1;
            x = m;
        }
    }

    ll ans = 0;

    for(int i=0; i<s; i++){
        if(x)ans += e[i] % x;
        else
            ans += e[i];
    }

    printf("%lld\n", ans);

}
