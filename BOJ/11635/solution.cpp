#include <stdio.h>

#include <limits.h>

#include <set>

#include <vector>

#include <algorithm>

using namespace std;

using ll = long long;

/* find a pair (c,d) s.t. ac + bd = gcd(a,b)
 * Dependencies: none */
pair<ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) return make_pair(1, 0);
    pair<ll, ll> t = extended_gcd(b, a % b);
    return make_pair(t.second, t.first - t.second * (a / b));
}

ll gcd(ll a, ll b){

    ll m = 1;

    while(m){

        m = a % b;
        a = b;
        b = m;

    }

    return a;

}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        // ax + by = c  (:positive integer x, y)
        // find(x0, y0)

        // ax + by = gcd(a,b) = d 
        // extended_gcd(a,b) ==> (x,y)

        // x0 = x * (c / d)
        // y0 = y * (c / d)

        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        ll d = gcd(a, -b);

        pair <ll,ll> st = extended_gcd(a, -b); // x,y

        pair <ll,ll> base = {st.first * c / d, -st.second * c / d};

        // x = x0 + b/d * k, y = y0 - a / d * k
        // (x >= 1 && y >= 1) 
        // (minimum x, then minimum y)

        // b/d * k >= 1-x0
        // bk >= d(1-x0)

        // -a/d*k >= 1-y0
        // ak <= -d(1-y0)

        ll x0 = base.first, y0 = base.second;

        ll k;

        k = d * (1-x0) / b;

        set <ll> K;

        for(ll i=k-1; i<=k+1; i++)K.insert(i);

        k = -d * (1-y0) / a;

        for(ll i=k-1; i<=k+1; i++)K.insert(i);

        pair <ll, ll> ans = {LLONG_MAX, LLONG_MAX};

        for(auto &k : K){

            ll va = x0 + b*k/d, vb = y0 - a*k/d;

            if(va < 1 || vb < 1)continue;

            if(ans.first > va){
                ans.first = va;
                ans.second = vb;
            }else if(ans.first == va && ans.second > vb){
                ans.second = vb;
            }

        }

        printf("%lld %lld\n", ans.first, ans.second);

    }

}
