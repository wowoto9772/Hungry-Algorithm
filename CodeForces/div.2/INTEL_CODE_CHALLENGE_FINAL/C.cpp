#include <cstdio>
#include <vector>

using ll = long long;

using namespace std;

using VI = vector <int>;
using VL = vector <ll>;
using VII = vector < pair<int,int> >;
using VLL = vector < pair<ll,ll> >;
using PII = pair <int,int>;
using PLL = pair <ll,ll>;

ll mod(ll a, ll b){
    return ((a%b)+b)%b;
}

ll gcd(ll a, ll b){
    ll c = 1;
    while(c){
        c = a % b;
        a = b;
        b = c;
    }return a;
}

ll lcm(ll a, ll b){
    return a / gcd(a,b) * b;
}

int extended_gcd(int a, int b, int &x, int &y) {
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
        int q = a / b;
        int t = b; b = a%b; a = t;
        t = xx; xx = x - q*xx; x = t;
        t = yy; yy = y - q*yy; y = t;
    }
    return a;
}

/* Chinese remainder theorem (special case): find z such that
 *  * z % m1 = r1, z % m2 = r2.  Here, z is unique modulo M = lcm(m1, m2).
 *   * Return (z, M).  On failure, M = -1. */

PII chinese_remainder_theorem(int m1, int r1, int m2, int r2) {
    int s, t;
    int g = extended_gcd(m1, m2, s, t);
    if (r1%g != r2%g) return {0, -1};
    return {mod(s*r2*m1 + t*r1*m2, m1*m2) / g, m1*m2 / g};
}

/* Chinese remainder theorem: find z such that
 *  * z % m[i] = r[i] for all i.  Note that the solution is
 *   * unique modulo M = lcm_i (m[i]).  Return (z, M). On 
 *    * failure, M = -1. Note that we do not require the a[i]'s
 *     * to be relatively prime. */

PII chinese_remainder_theorem(const VI &m, const VI &r) {
    PII ret = make_pair(r[0], m[0]);
    for (int i = 1; i < m.size(); i++) {
        ret = chinese_remainder_theorem(ret.second, ret.first, m[i], r[i]);
        if (ret.second == -1) break;
    }
    return ret;
}

int x[100003], y[100003];

PII xy[100003][4];

int main(){

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=1; i<=k; i++){
        scanf("%d %d", &x[i], &y[i]);
        xy[i][0] = {x[i], y[i]};
        xy[i][1] = {2*n-x[i], y[i]};
        xy[i][2] = {x[i], 2*m - y[i]};
        xy[i][3] = {2*n-x[i], 2*m-y[i]};
    }

    ll limit = lcm(2*n, 2*m);

    int p = 2*n, q = 2*m;

    VI M;

    for(int i=2; i*i <= p; i++){
        if(p%i)continue;

        ll v = 1;
        while(!(p%i)){
            p /= i;
            v *= i;
        }

        M.push_back(v);
    }

    if(p != 1)M.push_back(p);

    VI M2;

    for(int i=2; i*i <= q; i++){
        if(q%i)continue;
        
        ll v = 1;
        while(!(q%i)){
            q /= i;
            v *= i;
        }

        M2.push_back(v);
    }

    if(q != 1)M2.push_back(q);

    for(int i=1; i<=k; i++){

        for(int j=0; j<4; j++){

            VI R(M.size()), R2(M2.size());

            

        }

    }

    return 0;

}
