#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        int ans = 0;

        for(int i=1; i<=n; i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            int d = max({a, b, c});
            if(d > 0)ans += d;
        }

        printf("%d\n", ans);

    }

}
