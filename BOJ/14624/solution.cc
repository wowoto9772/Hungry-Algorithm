#include <cstdio>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    if(!(n&1))printf("I LOVE CBNU");
    else{

        for(int i=1; i<=n; i++){
            printf("*");
        }printf("\n");
        int c = (n+1) / 2;
        for(int i=1; i<=c; i++){
            for(int j=1; j<=c-i; j++)printf(" ");
            printf("*");
            if(i > 1){
                for(int j=1; j<=(i-1)*2-1; j++)printf(" ");
                printf("*");
            }
            printf("\n");
        }

    }

}
