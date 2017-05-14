#include <cstdio>

using namespace std;
using ll = long long;

const ll lmod = 1000000007LL;

ll f[100003] = {1, 1, 2, 6};
ll d[100003] = {1, 0, 1, 2};

int main(){

    int n;
    scanf("%d", &n);

    for(int i=4; i<=n; i++){
        f[i] = (f[i-1] * i) % lmod;
        d[i] = (i * (d[i-1]) + ((i&1) ? -1 : 1)) % lmod;
    }
    // a(n) = n! * d(n)
    // d(n) : subfactorial numbers
    // d(n) = (n-1)*(d(n-1)+d(n-2));
    
    printf("%lld\n", ( f[n] * d[n] ) % lmod);

}
