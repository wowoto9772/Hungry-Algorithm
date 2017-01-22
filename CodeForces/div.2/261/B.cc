#include <cstdio>
#include <limits.h>
#include <set>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int e[200003];

int main(){

    int n;
    scanf("%d", &n);

    int mv = INT_MAX, MV = 0;

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        if(mv > e[i])mv = e[i];
        if(MV < e[i])MV = e[i];
    }

    int d = MV - mv;

    printf("%d ", d);
    
    if(d == 0)printf("%lld\n", (ll)n*(n-1)/2);
    else{
        ll l = 0, r = 0;
        for(int i=1; i<=n; i++){
            if(e[i] == mv)l++;
            else if(e[i] == MV)r++;
        }

        printf("%lld\n", l*r);
    }

}
