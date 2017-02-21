#include <cstdio>
#include <algorithm>

using namespace std;

int e[103];

bool dp[53][450*53];

int main(){

    int n;
    scanf("%d", &n);

    int tot = 0;

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        tot += e[i];
    }

    dp[0][0] = true;

    int v = n/2;
    for(int i=1; i<=n; i++){
        for(int j=0; j<v; j++){
            for(int k=0; k<=j*450; k++){
                dp[j+1][k+e[i]] |= dp[j][k];
            }
        }
    }

    int ans = 55555555;
    int x = 5555555;

    for(int i=0; i<=v*450; i++)if(dp[v][i]){
        if(ans > abs(tot-2*i)){
            x = min(tot-i, i);
            ans = tot-2*i;
        }else if(ans == abs(tot-2*i)){
            x = min({x, i, tot-i});
        }
    }

    printf("%d %d\n", x, tot-x);

}
