#include <cstdio>
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

int main(){

    int n;
    scanf("%d", &n);

    // ax + by = gcd(a,b) * c = n

    PII sol = extended_gcd(3, 5);

    sol.first *= n, sol.second *= n;

    if(sol.first < 0 && sol.second < 0)printf("-1\n");
    else{

        int v = sol.first / 5;

        sol.first -= v * 5;
        sol.second += v * 3;

        if(sol.first < 0 || sol.second < 0)printf("-1\n");
        else{
            printf("%d\n", sol.first + sol.second);
        }
    }

}
