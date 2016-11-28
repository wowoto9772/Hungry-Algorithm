#include <cstdio>
#include <limits.h>
#include <algorithm>
 
using ll = long long;
using namespace std;

int l[100003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<n; i++){
        scanf("%d", &l[i]);
    }

    int p = INT_MAX;
    ll ans = 0;

    for(int i=1; i<n; i++){
        int c;
        scanf("%d", &c);
        p = min(p, c);
        ans += (ll)p * l[i];
    }

    scanf("%*d");
    printf("%lld\n", ans);

}
