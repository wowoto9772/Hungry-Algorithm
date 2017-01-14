#include <cstdio>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int a[5003];

ll itv(int l, int r, int h){

    if(l > r)
        return 0;

    int nh = INT_MAX;
    for(int i=l; i<=r; i++)if(nh > a[i])nh = a[i];

    // divide
    ll ret = 0;
    int p = l - 1;
    for(int i=l; i<=r; i++){
        if(a[i] == nh){
            ret += itv(p + 1, i - 1, nh);
            p = i;
        }
    }

    ret += itv(p + 1, r, nh); // remain

    // conquer
    return min(ret + nh - h, (ll)(r - l + 1)); // horizontal, vertical

}

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    printf("%lld\n", itv(1, n, 0));

    return 0;
}

// divide and conquer
