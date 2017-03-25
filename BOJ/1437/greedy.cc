#include <cstdio>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int c = 1;
    if(n == 0)c = 0;

    while(n >= 5){
        c *= 3;
        c %= 10007;
        n -= 3;
    }

    if(n == 2 || n == 4)c *= n;
    else if(n == 3)c *= 3;

    printf("%d\n", c%10007);

}
