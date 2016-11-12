#include <cstdio>

using ll = long long;
using namespace std;

int e[100003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    int b, c;
    scanf("%d %d", &b, &c);

    ll x = 0;

    for(int i=1; i<=n; i++){
        e[i] -= b;
        x++;
        if(e[i] > 0)x += e[i] / c + ((e[i] % c) > 0);
    }

    printf("%lld\n", x);

}
