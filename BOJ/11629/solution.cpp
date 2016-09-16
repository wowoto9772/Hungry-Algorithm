#include <cstdio>

#include <algorithm>

using namespace std;

const int cmod = 5318008;

int dp[5003][2];

int dy(int n, int s, int a, int b){

    for(int i=1; i<=n; i++)dp[i][0] = dp[i][1] = 0;

    dp[a][0] = 1;

    for(int i=1; i<=s; i++){

        int c = i&1;
        int p = 1^c;

        for(int j=1; j<=n; j++){

            dp[j][c] = dp[j][p];

            if(j > 1)dp[j][c] += dp[j-1][p];
            if(j < n)dp[j][c] += dp[j+1][p];

            dp[j][c] %= cmod;

        }
        
    }

    return dp[b][s&1];

}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);
        
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int x[] = {min(x1,x2), max(x1,x2)};
        int y[] = {min(y1,y2), max(y1,y2)};

        int w = x[1] - x[0];
        int h = y[1] - y[0];

        if(w > h)printf("%d\n", dy(n, w, y[0], y[1]));
        else
            printf("%d\n", dy(n, h, x[0], x[1]));

    }


}
