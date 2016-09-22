#include <stdio.h>

#include <algorithm>

using namespace std;

int dp[1003][1003];

int wp[1003][1003], rq[1003][1003], cq[1003][1003];

int dy(int r, int c){

    if(r > 1000 || c > 1000)return 0;

    int &ret = dp[r][c];

    if(ret != -1)return ret;

    int rem = wp[r][1000] + wp[1000][c] - wp[r][c] - (r+c-2); // L

    ret = 0;

    if(rem){
        ret = max(cq[r+1][1000] - cq[r+1][c] + dy(r+1, c),
                rq[1000][c+1] - rq[r][c+1] + dy(r, c+1));
    }

    return ret;

}

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=1000; i++)for(int j=1; j<=1000; j++)dp[i][j] = -1;

    for(int i=1; i<=n; i++){
        int _x, _y, a;
        scanf("%d %d %d", &_x, &_y, &a);
        wp[_x][_y] += a;
        rq[_x][_y]++;
        cq[_x][_y]++;
    }



    int aqw = 0, awp = 0;
    for(int i=1; i<=1001; i++){
        for(int j=1; j<=1001; j++){
            wp[i][j] += wp[i-1][j] + wp[i][j-1] - wp[i-1][j-1];
            rq[i][j] += rq[i-1][j];
            cq[i][j] += cq[i][j-1];
        }
    }

    printf("%d\n", rq[1000][1] + cq[1][1000] - cq[1][1] + dy(1, 1));

}
