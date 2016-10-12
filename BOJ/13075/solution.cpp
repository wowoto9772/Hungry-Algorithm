#include <cstdio>
#include <map>

using ll = long long;
const ll lmod = 1000000000LL;

using namespace std;

map <ll, ll> F;

ll fibonacci(ll a){
    if (a < 2) return 1;
    if (F[a]) return F[a];
    return F[a] = (fibonacci((a + 1) / 2)*fibonacci(a / 2) + fibonacci((a - 1) / 2)*fibonacci((a - 2) / 2)) % lmod;
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        ll a;
        scanf("%lld", &a);
        printf("%lld\n", fibonacci(a-1));
    }
}
