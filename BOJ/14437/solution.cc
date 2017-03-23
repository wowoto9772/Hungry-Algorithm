#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char str[3003];
int dp[3003][3003];

int main(){
    
    int k;
    scanf("%d %s", &k, str);
   
    dp[0][k] = 1;
    
    n = strlen(str);
    for(int i=0; i<n; i++){
        for(int j=k; j>=0; j--){
            for(int x='a'; x<='z'; x++){
                int c = x-str[i];
                if(c < 0)c += 26;
                if(c <= j){
                    dp[i+1][j-c] += dp[i][j];
                    dp[i+1][j-c] %= 1000000007;
                }
            }
        }
    }
    
    printf("%d\n", dp[n][0]);

}