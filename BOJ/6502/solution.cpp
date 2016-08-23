#include <stdio.h>
 
int main() {
 
    int tc = 0;
 
    int r, w, l;
 
   while(scanf("%d", &r) == 1){
 
        if(r == 0)break;
 
        scanf("%d %d", &w, &l);
 
        printf("Pizza %d ", ++tc);
 
        if(w*w + l*l <= 4*r*r){
            printf("fits ");
        }else{
            printf("does not fit ");
        }
 
        printf("on the table.\n");
 
    }
 
 
}
