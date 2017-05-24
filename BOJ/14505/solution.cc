#include <cstdio>
#include <cstring>

using namespace std;

int dp[1003][1003];
char str[1003];
int n;

int dy(int l, int r){
    int &ret = dp[l][r];
    if(ret != -1)return ret;
    ret = 1;
    for(int i=l+1; i<r; i++){
        for(int j=i; j<r; j++){
            if(str[i] == str[j]){
                ret += dy(i, j);
            }
        }
    }
    return ret;
}

int main(){
    
    scanf("%s", str);
    n = strlen(str);
    
    for(int i=0; i<n; i++)for(int j=i; j<n; j++)dp[i][j] = -1;

    int ans = 0;
        
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(str[i] == str[j]){
                ans += dy(i, j);
            }
        }
    }
    
    printf("%d\n", ans);

}