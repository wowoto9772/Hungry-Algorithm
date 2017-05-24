#include <cstdio>

using namespace std;

int main(){
    
    int a, b;
    char c;
    while(scanf("%d %c %d", &a, &c, &b) == 3){
        if(c == 'W' && (a|b) == 0)break;
        
        if(c == 'W'){
            a -= b;
        }else{
            a += b;    
        }
        if(a < -200)printf("Not allowed");
        else
            printf("%d", a);
        printf("\n");
    }

}