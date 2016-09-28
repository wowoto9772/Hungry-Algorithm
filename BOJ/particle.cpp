#include <vector>
#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

using ll = long long;

using VI = vector<int>;
using VII = vector< pair<int,int> >;
using VL = vector<ll>;
using VLL = vector< pair<ll,ll> >;
using PII = pair<int,int>;
using PLL = pair<ll, ll>;

int mod(int a, int b){
    return ((a%b)+b)%b;
}

int gcd(int a, int b){

    int m = 1;

    while(m){
        m = a % b;
        a = b;
        b = m;
    }

    return m;

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
 * z % m1 = r1, z % m2 = r2.  Here, z is unique modulo M = lcm(m1, m2).
 * Return (z, M).  On failure, M = -1. */

PII chinese_remainder_theorem(int m1, int r1, int m2, int r2) {
    int s, t;
    int g = extended_gcd(m1, m2, s, t);
    if (r1%g != r2%g) return {0, -1};
    return {mod(s*r2*m1 + t*r1*m2, m1*m2) / g, m1*m2 / g};
}

/* Chinese remainder theorem: find z such that
 * z % m[i] = r[i] for all i.  Note that the solution is
 * unique modulo M = lcm_i (m[i]).  Return (z, M). On 
 * failure, M = -1. Note that we do not require the a[i]'s
 * to be relatively prime. */

PII chinese_remainder_theorem(const VI &m, const VI &r) {
    PII ret = make_pair(r[0], m[0]);
    for (int i = 1; i < m.size(); i++) {
        ret = chinese_remainder_theorem(ret.second, ret.first, m[i], r[i]);
        if (ret.second == -1) break;
    }
    return ret;
}

int x[3], y[3], w, h, a, b;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        scanf("%d %d", &w, &h);
        for(int i=0; i<3; i++)scanf("%d %d", &x[i], &y[i]);
        scanf("%d %d", &a, &b);

        int g = gcd(a, b);

        a /= g, b /= g;

        int ans[] = {INT_MAX, INT_MAX, INT_MAX};

        for(int i=1; i<=2; i++){

            VII pt = {{x[i], y[i]}, {2*w - x[i], y[i]}, {x[i], 2*h - y[i]}, {2*w-x[i], 2*h-y[i]}};

            for(int j=0; j<4; j++){

                PII sol = chinese_remainder_theorem({2*w, 2*h}, {pt[j].first, pt[j].second});

                printf("%d %d\n", sol.first, sol.second);
                // a, b
                
                if(sol.first % a == 0 && sol.first % b == 0){
                    ans[i] = min(abs(sol.first - pt[j].first) / a, ans[i]);
                }

            }

        }

        if(min(ans[1], ans[2]) == INT_MAX)printf("O\n");
        else if(min(ans[1], ans[2]) == ans[1])printf("A\n");
        else
            printf("B\n");

    }

}

