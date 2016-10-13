#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int dp[404][404];

int main(){

    int n;
    scanf("%d", &n);

    vector <int> a, b;

    for(int i=1; i<=n; i++){
        int e;
        scanf("%d", &e);
        if(e)a.push_back(e);
    }

    for(int i=1; i<=n; i++){
        int e;
        scanf("%d", &e);
        if(e)b.push_back(e);
    }

    if(a.empty() || b.empty())printf("0\n");
    else{

        for(int i=0; i<=a.size(); i++)for(int j=0; j<=b.size(); j++)dp[i][j] = INT_MIN;

        dp[0][0] = 0;

        for(int k=1; k<=n; k++){
            for(int i=a.size(); i>=0; i--){
                for(int j=b.size(); j>=0; j--){
                    if(dp[i][j] == INT_MIN)continue;
                    if(i < a.size())dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                    if(j < b.size())dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
                    if(i < a.size() && j < b.size())dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + a[i]*b[j]);
                }
            }
        }

        printf("%d\n", dp[a.size()][b.size()]);

    }

}
