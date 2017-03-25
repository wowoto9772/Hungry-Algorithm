#include <cstdio>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int i;
    for(i=666;;i++){
        int j=i;
        while(j >= 100 && (j%1000) != 666)j /= 10;
        if(j%1000 == 666)n--;
        if(n == 0)break;
    }

    printf("%d\n", i);

}
