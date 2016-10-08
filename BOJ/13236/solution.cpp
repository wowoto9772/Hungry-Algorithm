#include <cstdio>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    while(n != 1){
        printf("%d ", n);
        if(n&1)n = n*3 + 1;
        else
            n >>= 1;
    }

    printf("%d\n", n);

}
