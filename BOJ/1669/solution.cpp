#include <cstdio>

using namespace std;
#define ll long long

int main(){
    int s, a;
    ll i;
    scanf("%d %d", &s, &a);

    for (i = 0; i*(i + 1) <= a - s && i*(i + 1) >= 0; i++) {}

    int c = (i - 1) * 2;

    if (a - s != (i - 1)*i) {
        int x = a - s - (i - 1)*i;
        if (x >= i) {
            c += x / i;
            if (x % i)c += 1;
        }
        else
            c += 1;
    }

    printf("%d\n", c);
}
