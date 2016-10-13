#include <cstdio>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main(){

    int n, b;
    scanf("%d %d", &n, &b);

    b <<= 1;

    vector < pair<ll,ll> > v;
    for(int i=1; i<=n; i++){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        x <<= 1;
        y <<= 1;
        v.emplace_back(x+y, x/2+y);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for(int i=0; i<v.size(); i++){
        ll p = 0;
        int c = 0;
        if(v[i].second <= b){
            p += v[i].second;
            c++;
            for(int j=0; j<v.size(); j++){
                if(i == j)continue;
                if(p + v[j].first <= b){
                    p += v[j].first;
                    c++;
                }else{
                    break;
                }
            }
        }
        ans = max(ans, c);
    }

    printf("%d\n", ans);

}
