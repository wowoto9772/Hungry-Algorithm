#include <cstdio>
#include <cstring>

using namespace std;

const int imod = 10007;

int dp[1003][1003];
char str[1003];

int dy(int l, int r){
    if(l == r)return 1;
    else if(l > r)return 0;
        
    int &ret = dp[l][r];
    if(ret != -1)return ret;
    ret = (dy(l+1, r) + dy(l, r-1)) % imod;
    if(str[l] == str[r])ret += 1;
    else
        ret -= dy(l+1, r-1);
    return ret = (ret + imod) % imod;
}

int main(){
    
    scanf("%s", str);
    int n = strlen(str);
    
    for(int i=0; i<n; i++)for(int j=i; j<n; j++)dp[i][j] = -1;
    printf("%d\n", dy(0, n-1));

}