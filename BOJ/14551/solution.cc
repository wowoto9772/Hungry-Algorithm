#include <cstdio>

using namespace std;

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    int c = 1;

    for(int i=1; i<=n; i++){
        int v;
        scanf("%d", &v);
        
        if(v)c = (c*v) % m;
    }
    
    printf("%d\n", c%m);

}