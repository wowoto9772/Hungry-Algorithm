#include <stdio.h>

int c[100003];

int main(){
    
    int n;
    scanf("%d", &n);
    
    n <<= 1;
    
    int d = 0, e = 0;
    
    for(int i=0; i<n; i++){
        int v;
        scanf("%d", &v);
        c[v] ^= 1;
        if(c[v])d++;
        else
            d--;
        if(e < d)e = d;
    }
    printf("%d\n", e);

}