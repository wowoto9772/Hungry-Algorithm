#include <cstdio>

using namespace std;

int main(){
    
    int n;
    scanf("%d", &n);
    
    int c = 0;
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        c += a*b;
    }
    
    printf("%d\n", c);

}