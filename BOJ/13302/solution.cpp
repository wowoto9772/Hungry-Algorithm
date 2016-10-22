#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[107][107], n;
bool cant[107];

int dy(int c, int q){

    if(c >= n+1)return 0;

    int &ret = dp[c][q];
    if(ret != -1)return ret;

    if(cant[c])ret = dy(c+1, q);
    else{
        ret = 10000 + dy(c+1, q);
        if(q >= 3)ret = dy(c+1, q-3);
        ret = min(ret, 25000 + dy(c+3, q+1));
        ret = min(ret, 37000 + dy(c+5, q+2));
    }

    return ret;

}

int main(){

    int d;
    scanf("%d %d", &n, &d);

    for(int i=1; i<=d; i++){
        int x;
        scanf("%d", &x);
        cant[x] = true;
    }

    memset(dp, 0xff, sizeof(dp));

    printf("%d\n", dy(1, 0));

}
