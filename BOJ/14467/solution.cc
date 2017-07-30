#include <stdio.h>

int p[13];

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=10; i++)p[i] = -1;
    int ans = 0;
    
    while(n--){
        int x, y;
        scanf("%d %d", &x, &y);
        if(p[x] != -1){
            if(p[x] != y)ans++;
        }
        p[x] = y;
    }
    
    printf("%d\n", ans);
}