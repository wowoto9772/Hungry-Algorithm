#include <stdio.h>
 
#include <algorithm>
 
using namespace std;
 
char S[10003], E[10003];
 
int dp[10003][13];
 
int n;
 
int dy(int c, int le) {
     
    if (c == n)return 0;
 
    if (dp[c][le] != -1)return dp[c][le];   
     
    int L = E[c] - ((S[c] + le - '0') % 10 + '0');
    if (L < 0)L += 10;
 
    int R = 10 - L;
 
    int goLe = L + dy(c + 1, (le + L) % 10);
    int goRi = R + dy(c + 1, le);
 
    return dp[c][le] = min(goLe, goRi);
 
}
int main()
{
    scanf("%d", &n);
 
    scanf("%s %s", S, E);
 
    for (int i = 0; i < n; i++)for (int j = 0; j < 10; j++)dp[i][j] = -1;
 
    printf("%d\n", dy(0, 0));
 
}
