#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[1003], b[1003];
int dp[1003][1003];

int dy(int l, int r){
    if(l == n || r == n)return 0;
    int &ret = dp[l][r];
    if(ret != -1)return ret;
    ret = 0;
    if(abs(a[l] - b[r]) <= 4)ret = 1 + dy(l+1, r+1);
    ret = max(ret, max(dy(l+1, r), dy(l, r+1)));
    return ret;
}

int main(){

    scanf("%d", &n);
    
    for(int i=0; i<n; i++)scanf("%d", &a[i]);
    for(int i=0; i<n; i++)scanf("%d", &b[i]);
    
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)dp[i][j] = -1;
    printf("%d\n", dy(0,0));

}