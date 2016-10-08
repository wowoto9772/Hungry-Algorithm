#include <cstdio>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

ll gcd(ll a, ll b){
    ll m = 1;
    while(m){
        m = a % b;
        a = b;
        b = m;
    }
    return a;
}

ll lcm(ll a, ll b){
    return a / gcd(a,b) * b;
}

vector <int> e;
int n;
ll cnt(int v){
    ll ret = 0;
    for(int i=1; i<(1<<n) && v; i++){
        ll x = 1;
        int y = 0;
        for(int j=0; j<n && x <= v; j++){
            if(i&(1<<j)){
                y++;
                x = lcm(x, e[j]);
            }
        }
        if(x <= v){
            ret += ((y&1) ? (1LL) : (-1LL)) * (v/x);
        }
    }
    return ret;
}

int main(){

    int L, R;
    scanf("%d %d %d", &n, &L, &R);

    e.resize(n);

    for(int i=0; i<n; i++){
        scanf("%d", &e[i]);
    }

    sort(e.begin(), e.end());
    e.resize(unique(e.begin(), e.end()) - e.begin());

    n = e.size();

    printf("%lld\n", cnt(R) - cnt(L-1));

}
