#include <cstdio>

using namespace std;

int c[333];

int main(){

    int n = 1;
    scanf("%d", &c[1]);

    while(c[n] != 1){
        if(c[n]&1)c[n+1] = c[n]*3 + 1;
        else
            c[n+1] = c[n]/2;
        n++;
    }

    printf("%d\n", n);

}
