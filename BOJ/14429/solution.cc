#include <cstdio>

using namespace std;

int main(){
    
    int n;
    scanf("%d", &n);
    
    int ans = 987654321, x;
    
    for(int i=1; i<=n; i++){
        int j, m;
        scanf("%d %d", &j, &m);
        
        int r = (j-1) % (1+m);
        int l = 1 + ((j-1-r) / (1+m)) * 2 + 1;
        if(ans > l)ans = l, x = i;
    }
    
    printf("%d %d\n", x, ans);

}
