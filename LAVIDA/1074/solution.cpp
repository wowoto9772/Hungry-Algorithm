#include <stdio.h>
#include <memory.h>

int n;
int dp[1003], I[1003];

int M(int a, int b){ return a < b ? b : a; }

int dy(int c){
	if (dp[c] != -1)return dp[c];

	dp[c] = 1;

	for (int i = c + 1; i <= n; i++){
		if (I[c] < I[i]){
			dp[c] = M(dp[c], 1 + dy(i));
		}
	}

	return dp[c];

}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &I[i]);

	memset(dp, 0xff, sizeof(dp));

	int ans = 1;

	for (int i = 1; i <= n; i++)ans = M(ans, dy(i));

	printf("%d\n", ans);
}