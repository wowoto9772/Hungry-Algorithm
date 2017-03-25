#include <cstdio>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int c = 1;

    while(n >= 5){
        c *= 3;
        c %= 10007;
        n -= 3;
    }

    printf("%d\n", (n*c)%10007);

}
