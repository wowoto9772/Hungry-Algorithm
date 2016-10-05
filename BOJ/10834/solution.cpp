#include <cstdio>

using ll = long long;

using namespace std;

ll gcd(ll a, ll b){
    ll m = 1;
    while(m){
        m = a % b;
        a = b;
        b = m;
    }return a;
}

int main(){

    int n;
    scanf("%d", &n);

    ll p = 1, s = 1;

    int d = 0;

    for(int i=1; i<=n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if(c == 1)d ^= 1;

        p *= a, s *= b;

        ll g = gcd(p, s);
        p /= g, s /= g;
    }

    printf("%d %d\n", d, s);

}
