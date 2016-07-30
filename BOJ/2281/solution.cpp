#include <stdio.h>
#include <memory.h>
#include <limits.h>

int I[1003];
int dp[1003][1003];
int n, m;

int mn(int a, int b){ return a < b ? a : b; }

int dy(int c, int l){
	if (dp[c][l] != -1)return dp[c][l];
	if (c == n - 1){
		if (l + 1 + I[c + 1] <= m){
			return dp[c][l] = 0;
			//return dp[c][l] = (m-(l+I[c+1]+1))*(m-(l+I[c+1]+1));
		}
		else{
			return dp[c][l] = (m - l)*(m - l);
			//return dp[c][l] = (m-l)*(m-l) + (m-I[c+1])*(m-I[c+1]);
		}
	}

	dp[c][l] = INT_MAX;

	if (I[c + 1] + l + 1 <= m){
		dp[c][l] = mn(dp[c][l], dy(c + 1, l + I[c + 1] + 1));
	}
	dp[c][l] = mn(dp[c][l], (m - l)*(m - l) + dy(c + 1, I[c + 1]));

	return dp[c][l];
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)scanf("%d", &I[i]);

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(1, I[1]));
}

// 제일 마지막 줄은 앞으로 이름을 적을 기회가 있으므로 계산하지 않는다.