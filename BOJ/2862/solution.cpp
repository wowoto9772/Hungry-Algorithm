#include <cstdio>

using ll = long long;
using namespace std;

ll p[100] = {1, 2, };

int main(){

    int top = 0;

    ll n;
    scanf("%lld", &n);

    for(int i=1;;i++){
        if(i > 1)p[i] = p[i-1] + p[i-2];
        if(p[i] > n)break;
        top = i;
    }

    ll ans = -1;

    for(int i=top; i>=0; i--){
        if(n-p[i] >= 0){
            n -= p[i];
            ans = p[i];
        }
    }

    printf("%lld\n", ans);

}
