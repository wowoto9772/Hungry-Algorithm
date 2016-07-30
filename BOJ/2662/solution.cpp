// just dp

#include <stdio.h>
#include <memory.h>

int dp[23][303], s[23][303], I[23][303];
int a, n;

int dy(int c, int m){
	if (c > n)return 0;
	
	if (dp[c][m] != -1)return dp[c][m];

	dp[c][m] = 0;

	for (int i = a - m; i >= 0; i--){
		if (dp[c][m] < I[c][i] + dy(c + 1, m + i)){
			dp[c][m] = I[c][i] + dy(c + 1, m + i);
			s[c][m] = i;
		}
	}
	
	return dp[c][m];
}

int main()
{
	scanf("%d %d", &a, &n);

	int k;
	for (int i = 1; i <= a; i++){
		scanf("%d", &k);
		for (int j = 1; j <= n; j++){
			scanf("%d", &I[j][k]);
		}
	}

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(1, 0));

	int m = 0;

	for (int i = 1; i < n; i++){
		printf("%d ", s[i][m]);
		m += s[i][m];
	}printf("%d\n", s[n][m]);
}