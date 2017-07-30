#include <stdio.h>

int main(){
    
    int n;
    scanf("%d", &n);
    
    int a = 0;
    for(int i=0; i<n; i++){
        int b;
        scanf("%d", &b);
        if(b < 0)b *= -1;
        a += b;
    }
    
    printf("%d\n", a<<1);

}