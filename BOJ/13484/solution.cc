#include <cstdio>

using namespace std;

int main(){

    int x, n;
    scanf("%d %d", &x, &n);

    int ans = 0;

    for(int i=1; i<=n; i++){
        int v;
        scanf("%d", &v);

        ans += x-v;
    }
    
    printf("%d\n", ans+x);

}
