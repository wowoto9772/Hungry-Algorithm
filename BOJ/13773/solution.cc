#include <cstdio>

using namespace std;

int main(){
    
    int v;
    while(scanf("%d", &v) == 1 && v){
        printf("%d ", v);
        if(v >= 1896 && v % 4 == 0){
            if(1914 <= v && v <= 1918)printf("Games cancelled");
            else if(1939 <= v && v <= 1945)printf("Games cancelled");
            else if(v > 2020)printf("No city yet chosen");
            else
                printf("Summer Olympics");
        }
        else
            printf("No summer games");
        puts("");
    }

}