#include <stdio.h>
#include <memory.h>

int n;
int I[2][100003];
int dp[2][100003];

int M(int a, int b){ return a < b ? b : a; }

int dy(int i, int j){
	if (dp[i][j] != -1)return dp[i][j];

	dp[i][j] = 0;

	if (j < n){
		if (i)dp[i][j] = I[i][j] + dy(0, j + 1);
		else
			dp[i][j] = I[i][j] + dy(1, j + 1);
	}

	for (int a = 0; a <= 1; a++){
		for (int b = j + 2; b <= n && b <= j+4; b++){
			dp[i][j] = M(dp[i][j], I[i][j] + dy(a, b));
		}
	}

	if (!dp[i][j])dp[i][j] = I[i][j];

	return dp[i][j];
}

int main()
{

	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);
		
		for (int i = 0; i <= 1; i++){
			for (int j = 1; j <= n; j++){
				scanf("%d", &I[i][j]);
			}
		}

		memset(dp, 0xff, sizeof(dp));

		int ans = 0;

		for (int i = 0; i <= 1; i++){
			for (int j = 1; j <= n; j++){
				int k = dy(i, j);
				ans = ans < k ? k : ans;
			}
		}

		printf("%d\n", ans);
	}

}