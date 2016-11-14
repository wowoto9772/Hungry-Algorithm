#include <cstdio>
#include <algorithm>
#include <limits.h>

using namespace std;
using ll = long long;

ll x[4], y[4];

ll cst(ll v){
    ll ret = LLONG_MAX;
    ll a[] = {v, v, -v, -v};
    ll b[] = {v, -v, v, -v};
    int e[] = {0,1,2,3};
    while(true){
        ll cmp = 0;
        for(int i=0; i<4; i++){
            cmp += abs(x[i] - a[e[i]]) + abs(y[i] - b[e[i]]);
        }
        ret = min(ret, cmp);
        if(!next_permutation(e, e+4))break;
    }

    return ret;

}

int main(){

    for(int i=0; i<4; i++){
        scanf("%lld %lld", &x[i], &y[i]);
    }

    ll ans = LLONG_MAX, ans2 = 0;

    for(int i=0; i<4; i++){
        ll tmp = cst(abs(x[i]));
        if(ans > tmp){
            ans = tmp;
            ans2 = abs(x[i]);
        }else if(ans == tmp){
            ans2 = max(ans2, abs(x[i]));
        }
        tmp = cst(abs(y[i]));
        if(ans > tmp){
            ans = tmp;
            ans2 = abs(y[i]);
        }else if(ans == tmp){
            ans2 = max(ans2, abs(y[i]));
        }
    }

    if(ans2 == 0)ans2 = 1;
    else
        ans2 <<= 1;

    printf("%lld\n", ans2);

}
