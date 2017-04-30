#include <cstdio>
#include <algorithm>

using namespace std;

int dp[730][730][2][2];
int ti[1450];

int dy(int i, int j, int p, int q){
    if(i > 720 || j > 720)return 987654321;
    if(i+j == 1440){
        return p != q;
    }
    int &ret = dp[i][j][p][q];
    if(ret != -1)return ret;
    if(ti[i+j] == -1){
        ret = min(dy(i, j+1, 1, q) + (p != 1), dy(i+1, j, 0, q) + (p != 0));
    }else{
        if(ti[i+j]){
            ret = dy(i+1, j, 0, q) + (p != 0);
        }else{
            ret = dy(i, j+1, 1, q) + (p != 1);
        }
    }
    return ret;
}

int main(){

    int t;
    scanf("%d", &t);

    int tc = 0;

    while(t--){

        for(int i=0; i<1440; i++)ti[i] = -1;
        for(int i=0; i<730; i++){
            for(int j=0; j<730; j++){
                dp[i][j][0][0] = dp[i][j][0][1] = dp[i][j][1][1] = dp[i][j][1][0] = -1;
            }
        }

        int x, y;
        scanf("%d %d", &x, &y);
        while(x--){
            int a, b;
            scanf("%d %d", &a, &b);
            for(int j=a; j<b; j++)ti[j] = 0;
        }
        while(y--){
            int a, b;
            scanf("%d %d", &a, &b);
            for(int j=a; j<b; j++)ti[j] = 1;
        }

        printf("Case #%d: %d\n", ++tc, min(dy(0, 0, 0, 0), dy(0, 0, 1, 1)));
    }

}
