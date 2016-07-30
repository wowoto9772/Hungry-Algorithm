#include <stdio.h>
#include <memory.h>

#define max(a, b) (a) < (b) ? (b) : (a)

int dp[1003][4];
int I[1003];
bool chk[1003];
int n, m;

int dy(int c, int s){
	if (c > n)return 0;
	if (dp[c][s] != -1)return dp[c][s];

	if (s == 2){
		dp[c][s] = dy(c + 1, 0);
	}
	else{
		if (chk[c])dp[c][s] = dy(c + 1, 0);
		else{
			dp[c][s] = max(I[c] + dy(c + 1, s + 1), dy(c + 1, 0));
		}
	}

	return dp[c][s];
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)scanf("%d", &I[i]);
	for (int i = 1; i <= m; i++){
		int a;
		scanf("%d", &a);
		chk[a - 1] = true;
	}

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(1, 0));
}