#include <cstdio>

using namespace std;

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            int d = i&1, e = j&1;
            if(d^e)printf(".");
            else
                printf("*");
        }printf("\n");
    }

}
