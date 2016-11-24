#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int e[2003];
int dp[2003][2003];
int n;

int dy(int l, int r){
    if(l == n || r == n)return 0;
    int &ret = dp[l][r];
    if(ret != -1)return ret;
    if(r == 0){
        ret = min(dy(l, l+1), dy(l+1, 0) + abs(e[l] - e[l+1]));
    }else{
        int M = max(l, r);
        ret = min(dy(M+1, r) + abs(e[M+1] - e[l]), dy(l, M+1) + abs(e[M+1] - e[r]));
    }
    return ret;
}

int main(){

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
    }

    int ans = INT_MAX;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = -1;
        }
    }

    printf("%d\n", dy(1, 0));

}
