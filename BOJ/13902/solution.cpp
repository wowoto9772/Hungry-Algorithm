#include <cstdio>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

int dp[10003];
bool pos[10003];
int c[1003];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    pos[0] = true;

    for(int i=1; i<=m; i++){
        scanf("%d", &c[i]);
    }
    for(int i=1; i<=m; i++){
        for(int j=i+1; j<=m; j++){
            if(c[i]+c[j] <= n){
                pos[c[i]+c[j]] = true;
            }
        }
        pos[c[i]] = true;
    }

    vector <int> v;
    for(int i=1; i<=n; i++)if(pos[i])v.push_back(i);

    for(int i=1; i<=n; i++)dp[i] = INT_MAX;

    for(int i=1; i<=n; i++){
        for(int j=0; j<v.size() && v[j] <= i; j++){
            if(dp[i-v[j]] == INT_MAX)continue;
            dp[i] = min(dp[i], dp[i-v[j]] + 1);
        }
    }

    if(dp[n] == INT_MAX)dp[n] = -1;
    printf("%d\n", dp[n]);

}
