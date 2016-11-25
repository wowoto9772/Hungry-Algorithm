#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int up = 0, down = 0, ans = INT_MIN;

    bool allN = true;
    int maxV = INT_MIN;

    for(int i=1; i<=n; i++){
        int e;
        scanf("%d", &e);

        if(e >= 0)allN = false;
        maxV = max(maxV, e);

        down += e;
        ans = max(ans, down);
        up += e;
        ans = max(ans, up);
        if(down < up-e){
            down = up-e;
            ans = max(ans, down);
        }
        if(up < 0)up = 0;
        if(down < 0)down = 0;
    }

    if(allN){
        ans = maxV;
    }

    printf("%d\n", ans);

}
