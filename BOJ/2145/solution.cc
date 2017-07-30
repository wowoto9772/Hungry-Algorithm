#include <stdio.h>

int nxt(int v){
    int r = 0;
    while(v){
        r += v%10;
        v /= 10;
    }return r;
}

int main(){
    
    int v;
    while(scanf("%d", &v) == 1 && v){
        while(v >= 10){
            v = nxt(v);
        }
        printf("%d\n", v);
    }

}