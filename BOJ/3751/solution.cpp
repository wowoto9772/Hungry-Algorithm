#include <cstdio>
#include <set>
#include <algorithm>

using ll = long long;
using namespace std;

ll gcd(ll a, ll b){
    ll m = 1;
    while(m){
        m = a%b;
        a = b;
        b = m;
    }return a;
}

ll lcm(ll a, ll b){
    return (a / gcd(a,b)) * b;
}

vector <ll> data;

ll cnt(ll v){
    int res = 0;
    int l = 0, r = data.size()-1, m;
    while(l <= r){
        m = (l+r) / 2;
        if(data[m] <= v){
            res = max(res, m);
            l = m + 1;
        }else{
            r = m - 1;
        }
    }return res;
}

ll vmax = 1000000000000LL;

int main(){

    vector <ll> my;
    my.push_back(0);

    for(int i=0; i<my.size(); i++){
        ll e = my[i];
        if(e*10LL+4LL <= vmax){
            my.push_back(e*10LL+4LL);
        }
        if(e*10LL+7LL <= vmax){
            my.push_back(e*10LL+7LL);
        }
    }

    sort(my.begin(), my.end());

    set <ll> e;
    e.insert(1LL);

    for(auto &v : e){
        for(int k=1; k<my.size(); k++){
            if(v*my[k] <= vmax){
                e.insert(my[k]*v);
            }else{
                break;
            }
        }
    }

    for(auto &v : e){
        data.push_back(v);
    }

    int t;
    scanf("%d", &t);

    while(t--){

        ll l, r; 
        scanf("%lld %lld", &l, &r);

        printf("%lld\n", cnt(r) - cnt(l-1));

    }

}
