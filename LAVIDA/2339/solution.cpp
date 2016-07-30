#include <stdio.h>

int dp[1000001];

int main()
{
	int n, a, top = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &a);
		if (dp[top] < a){
			dp[++top] = a;
		}
		else{
			int l = 1, r = top, m;
			while (l <= r){
				m = (l + r) / 2;
				if (dp[m] < a)l = m + 1;
				else if (dp[m] > a)r = m - 1;
				else{
					break;
				}
			}

			if (dp[m] > a)dp[m] = a;
			else
				dp[m + 1] = a;
		}
	}

	printf("%d\n", top);
}