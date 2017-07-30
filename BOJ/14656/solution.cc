#include <stdio.h>

int main(){
    
    int n;
    scanf("%d", &n);
    
    int c = 0;
    
    for(int i=1; i<=n; i++){
        int v;
        scanf("%d", &v);
        if(v != i)c++;
    }
    
    printf("%d\n", c);

}