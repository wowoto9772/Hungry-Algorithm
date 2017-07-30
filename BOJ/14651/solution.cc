#include <cstdio>

using namespace std;
const int imod = 1000000009;

int dp[33339][3];
int n;
int dy(int c, int r){
    if(c == n)return r == 0;
    else{
        int &ret = dp[c][r];
        if(ret != -1)return ret;
        ret = 0;
        for(int i=0; i<3; i++){
            ret += dy(c+1, (r+i)%3);
            ret %= imod;
        }
        return ret;
    }
}

int main(){
    
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)dp[i][0] = dp[i][1] = dp[i][2] = -1;
    
    int ans = (dy(1,1) + dy(1,2)) % imod;
    printf("%d\n", ans);

}