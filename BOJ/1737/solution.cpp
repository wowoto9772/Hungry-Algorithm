#include <cstdio>
#include <cmath>
#include <map>

using ll = long long;
using namespace std;

map <double, ll> dp;

const ll lmod = 1000000000000000000LL;
const double pi = acos(-1.0);

ll p(double c){
    if(0 <= c && c <= pi)return 1;
    else if(dp.find(c) == dp.end()){
        return dp[c] = (p(c-1) + p(c-pi)) % lmod;
    }else{
        return dp[c];
    }
}

int main(){

    int n;
    while(scanf("%d", &n) == 1 && n != -1){
        printf("%lld\n", p(n));
    }

}
