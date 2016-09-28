#include <stdio.h>

#include <algorithm>

using namespace std;

using ll = unsigned long long;

int main(){

    int n;
    scanf("%d", &n);

    ll p = 2;

    for(ll i=1; i<=n; i++){

        ll s = (i+1);

        for(ll k=1; k<=1800; k++){

            ll c = (k*s);
            c *= c;

            c -= p;

            if(c < 0 || c % i)continue;

            printf("%llu\n", c/i);

            p = k*s;

            break;

        }

    }


}
