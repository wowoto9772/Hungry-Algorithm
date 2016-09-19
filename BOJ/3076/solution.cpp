#include <stdio.h>

char str[103][103];

int main(){

    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);

    for(int i=1; i<=n*r; i++){
        for(int j=1; j<=m*c; j++){
            int a = (i-1) / r, b = (j-1) / c;
            a&=1; b&=1;
            if(a^b)printf(".");
            else
                printf("X");
        }printf("\n");
    }

}
