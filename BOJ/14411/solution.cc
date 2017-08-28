#include <cstdio>

using namespace std;
using ll = long long;

int h[10000003];

int main(){
    
    int n;
    scanf("%d", &n);
    
    ll ans = 0;
    int maxy = 0;
    
    for(int i=0; i<n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x >>= 1;
        y >>= 1;
        if(h[y] < x)h[y] = x;
        if(maxy < y)maxy = y;
    }
    
    for(int i=maxy; i>=1; i--){
        if(h[i] < h[i+1])h[i] = h[i+1];
        ans += h[i];
    }
    
    printf("%lld\n", ans<<2);

}