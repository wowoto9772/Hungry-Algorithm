#include <cstdio>

#include <vector>
#include <map>
#include <algorithm>

using ll = long long;

const ll lmod = 1000000007;

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    vector <int> v(n);

    map <int, int> c;

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
        c[v[i]]++;
    }

    sort(v.begin(), v.end());

    v.resize(unique(v.begin(), v.end()) - v.begin());

    vector <ll> lsum(v.size()), rsum(v.size());

    for(int i=0; i<v.size(); i++){
        lsum[i] = ((ll)v[i] * c[v[i]]) % lmod;
        if(i){
            lsum[i] += lsum[i-1];
            lsum[i] %= lmod;
        }
    }

    for(int i=v.size()-1; i>=0; i--){
        rsum[i] = ((ll)v[i] * c[v[i]]) % lmod;
        if(i != v.size()-1){
            rsum[i] += rsum[i+1];
            rsum[i] %= lmod;
        }
    }

    ll ans = 0;

    for(int i=1; i<=v.size()-2; i++){
        ll c = (lsum[i] - lsum[i-1] + lmod) % lmod;
        ans += (((c * lsum[i-1]) % lmod) * rsum[i+1]) % lmod;
        ans %= lmod;
    }

    printf("%lld\n", ans);

}
