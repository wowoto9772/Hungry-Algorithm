#include <cstdio>

using namespace std;
using ll = long long;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        ll a, n;
        scanf("%lld %lld", &a, &n);
        int b[40] = {};
        int top = 0;
        while(a){
            b[top++] = a % n;
            a /= n;
        }
        bool p = true;
        for(int i=0; i<top/2; i++){
            p &= (b[i] == b[top-1-i]);
        }

        printf("%d\n", ((p) ? 1 : 0));
    }

}
