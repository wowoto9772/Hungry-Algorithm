#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const ll lmod = 1000000007LL;

ll a[1000003] = {0, 1, 1};
ll s[1000003] = {0, 1, 2};

int main(){

    // a[n] = 2<<(n-2) * sum(a[1], a[2], ..., a[n-1])

    ll t = 2;
    for(int i=3; i<=1000000; i++){
        a[i] = (t * s[i-1]) % lmod;
        s[i] = (s[i-1] + a[i]) % lmod;
        t <<= 1;
        t %= lmod;
    }

    int q;
    scanf("%d", &q);

    while(q--){
        int x;
        scanf("%d", &x);

        ll i, j, k;

        if(x == 1){ // gcd
            scanf("%lld %lld %lld", &i, &j, &k);
            if(j > k)swap(j, k);
            printf("%lld\n", (i*a[j]) % lmod);
        }else if(x == 2){ // lcm
            scanf("%lld %lld %lld", &i, &j, &k);
            if(j > k)swap(j, k);
            ll v = i;
            int c = 0;
            while(!(v&1)){
                v >>= 1;
                c++;
            }
            if(k <= 2)printf("%d\n", c);
            else
                printf("%d\n", c+k-1);
        }else if(x == 3){
            scanf("%lld %lld %lld", &i, &j, &k);
            if(j > k)swap(j, k);
            printf("%lld\n", (i*(s[k]-s[j-1]+lmod)) % lmod);
        }else if(x == 4){
            scanf("%lld %lld", &i, &j);
            printf("%lld\n", (i*a[j]) % lmod);
        }
    }

}
