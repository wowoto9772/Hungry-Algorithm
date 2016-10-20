#include <cstdio>

using ll = long long;

using namespace std;

ll c[63] = {1};

ll cnt(ll v){

    ll ret = 0;
    int top = 0;

    while(v){
        if(v&1)ret += c[top];
        v >>= 1;
        top++;
    }

    return ret;

}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    for(int i=1; i<=59; i++){
        c[i] = c[i-1] * 2LL + 1LL;
    }

    int t;
    scanf("%d", &t);

    while(t--){

        ll x, y;
        scanf("%lld %lld", &x, &y);

        printf("%lld\n", cnt(y) - cnt(x));

    }

}
