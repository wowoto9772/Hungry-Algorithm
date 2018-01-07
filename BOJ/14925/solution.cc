#include <cstdio>

using namespace std;

int dp[1003][1003];

int query(int a, int b, int x, int y){
    return dp[x][y] - dp[a-1][y] - dp[x][b-1] + dp[a-1][b-1];
}

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            int e;
            scanf("%d", &e);
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (e == 0);
        }
    }

    int ans = 0;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            while(i+ans <= r && j+ans <= c){
                if(query(i, j, i+ans, j+ans) == (i+ans - i+1) * (j+ans - j+1))ans++;
                else
                    break;
            }
        }
    }

    printf("%d\n", ans);

}
