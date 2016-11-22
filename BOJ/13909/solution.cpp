#include <cstdio>

using ll = long long;
using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    ll c = 0;
    int d = 3, e = 1;

    for(int i=1; i<=n; i++){
        c += d;
        if(c >= n)break;
        d += 2;
        e++;
    }

    printf("%d\n", e);

}
