#include <cstdio>
#include <limits.h>
#include <vector>

using namespace std;

using ll = long long;
using VI = vector<int>;
using VII = vector< pair<int,int> >;
using VL = vector<ll>;
using VLL = vector< pair<ll,ll> >;
using PII = pair<int,int>;
using PLL = pair<ll, ll>;

/* find a pair (c,d) s.t. ac + bd = gcd(a,b)
 * Dependencies: none */

PII extended_gcd(ll a, ll b) {
    if (b == 0) return make_pair(1, 0);
    PII t = extended_gcd(b, a % b);
    return {t.second, t.first - t.second * (a / b)};
}

ll gcd(ll a, ll b){
    ll m = 1;
    while(m){
        m = a % b;
        a = b;
        b = m;
    }return a;
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        ll a, b, n;
        scanf("%lld %lld %lld", &a, &b, &n);

        ll g = gcd(a, b);

        if(n % g){
            printf("Impossible\n");
            continue;
        }

        a /= g, b /= g, n /= g;

        PLL sol = extended_gcd(a, b);

        if(sol.first < 0 && sol.second < 0)printf("Impossible\n");
        else{

            sol.first *= n, sol.second *= n;
            PLL csol = sol;

            int ans = INT_MAX;
            int x = sol.first, y = sol.second;
            while(sol.second >= 0){
                if(sol.first >= 0 && ans > sol.second + sol.first){
                    ans = sol.second + sol.first;
                    x = sol.first, y = sol.second;
                }
                sol.first += b;
                sol.second -= a;
            }

            sol = csol;
            while(sol.first >= 0){
                if(sol.second >= 0 && ans > sol.second + sol.first){
                    ans = sol.second + sol.first;
                    x = sol.first, y = sol.second;
                }
                sol.first -= b;
                sol.second += a;
            }
            if(ans == INT_MAX)printf("Impossible\n");
            else
                printf("%d %d\n", x, y);
        }

    }
}
