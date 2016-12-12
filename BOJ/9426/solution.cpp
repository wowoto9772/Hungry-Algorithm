#include <cstdio>
#include <limits.h>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using ll = long long;
using namespace std;

ll e[250003];

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    map <ll, int> c;
    set < pair<ll, int> > my;

    for(int i=1; i<=n; i++){
        scanf("%lld", &e[i]);
        if(i <= k)my.emplace(make_pair(e[i], ++c[e[i]]));
    }

    my.emplace(make_pair(LLONG_MIN, 0));
    my.emplace(make_pair(LLONG_MAX, 0));
    set < pair<ll, int> > ::iterator it = my.begin();

    int d = (k+1) / 2;
    for(int i=1; i<=d; i++)it++;

    ll ans = (*it).first;

    for(int i=k+1; i<=n; i++){
        ll v = (*it).first;
        my.emplace(e[i], ++c[e[i]]);
        if(e[i-k] <= v)it++;
        my.erase(my.lower_bound(make_pair(e[i-k], 0)));
        if(e[i] < v)it--;
        ans += (*it).first;
    }

    printf("%lld\n", ans);

}
