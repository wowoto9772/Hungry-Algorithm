#include <cstdio>

using namespace std;

int main(){
    
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("%d %d\n", (a*b) >> 1, a*b-1);

}