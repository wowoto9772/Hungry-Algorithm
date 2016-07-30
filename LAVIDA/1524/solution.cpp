#include <stdio.h>

int dp[40003];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int d = 1;
		scanf("%d", &dp[1]);
		for (int i = 2; i <= n; i++){
			int a;
			scanf("%d", &a);

			int l = 1, r = d, m;
			while (l <= r){
				m = (l + r) / 2;
				if (dp[m] > a)r = m - 1;
				else
					l = m + 1;
			}

			if (m == d){
				if (dp[m] < a){
					dp[++m] = a;
					d++;
				}
				else if (dp[m] > a){
					dp[m] = a;
				}
			}
			else{
				if (dp[m] > a)dp[m] = a;
				else if (dp[m] < a){
					dp[m + 1] = a;
				}
			}
		}

		printf("%d\n", d);
	}
}