#include <cstdio>

using namespace std;

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    int r = 1;

    for(int i=a; i<=b; i++){
        r *= ((i-1)*i/2 + i) % 14579;
        r %= 14579;
    }

    printf("%d\n", r);

}
