#include <cstdio>

using namespace std;

int main(){
    
    int x, y;
    scanf("%d %d", &x, &y);
    
    if(x < 0){
        if(y < 0)puts("3");
        else
            puts("2");
    }else{
        if(y < 0)puts("4");
        else
            puts("1");
    }

}