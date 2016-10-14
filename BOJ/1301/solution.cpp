#include <cstdio>
#include <map>
#include <vector>

using ll = long long;
using namespace std;

map < vector <int>, ll > dp;

int c[5];

ll dy(vector <int> v){
    if(dp.find(v) != dp.end())return dp[v];
    ll &ret = dp[v];
    dp[v] = 0;
    int p = v[v.size()-2];
    int q = v.back();
    int d = 0;
    for(int i=0; i<v.size()-2; i++){
        if(v[i] == 0){
            d++;
            continue;
        }
        else if(i == p || i == q){
            continue;
        }else{
            v[i]--;
            v[v.size()-2] = q;
            v.back() = i;

            ret += dy(v);

            v[v.size()-2] = p;
            v.back() = q;
            v[i]++;
        }
    }

    if(d == v.size()-2){
        ret = 1;
    }
    return ret;
}

int main(){

    int n;
    scanf("%d", &n);

    vector <int> v;

    for(int i=0; i<n; i++){
        scanf("%d", &c[i]);
        v.push_back(c[i]);
    }

    v.push_back(-1);
    v.push_back(-1);

    printf("%lld\n", dy(v));

}
