#include <cstdio>

using namespace std;

int main(){
    
    int t;
    scanf("%d", &t);
    
    while(t--){
        int v;
        scanf("%d", &v);
        printf("%d is ", v);
        if(v&1)printf("odd");
        else
            printf("even");
        printf("\n");
    }

}