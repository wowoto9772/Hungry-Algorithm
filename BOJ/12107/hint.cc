#include <cstdio>
#include <memory.h>

using namespace std;

int dp[1<<22][2], n;

int dy(int s, int p){
    if(s == (1<<n)-1){
        return !p;
    }
    int &ret = dp[s][p];
    if(ret != -1)return ret;
    ret = p;
    for(int i=1; i<=n; i++){
        if(s&(1<<(i-1)))continue;
        int d = 0;
        for(int j=1; j<=i; j++){
            if(i%j == 0)d |= 1<<(j-1);
        }
        ret = dy(s|d, !p);
        if(ret == !p)break;
    }
    return ret;
}

int main(){

    scanf("%d", &n);

    memset(dp, 0xff, sizeof(dp));

    printf("%c\n", (dy(0, 0) == 1) ? 'A' : 'B');

} // BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA...
