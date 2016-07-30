#include <stdio.h>
#include <memory.h>


int max(int a, int b){ return a < b ? b : a; }

int I[1003];
int dp[1003][2];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);


		for (int i = 1; i <= n; i++){
			scanf("%d", &I[i]);
			dp[i][0] = dp[i][1] = 1;
		} // 0 < 1 >

		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				// < increase
				if (I[i] > I[j])dp[j][1] = max(dp[j][1], dp[i][0] + 1);
				// > decrease
				if (I[i] < I[j])dp[j][0] = max(dp[j][0], dp[i][1] + 1);
			} 
			ans = max(ans, dp[i][0]);
			ans = max(ans, dp[i][1]);
		}

		printf("%d\n", ans);
	}
}