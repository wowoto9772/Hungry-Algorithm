#include <stdio.h>
#define mod 1000000007

int F[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int dp[500001];

int main()
{
	dp[0] = 1;
	dp[6] = -1; // do not use leading zero.
	for (int i = 2; i <= 500000; i++){
		for (int j = 0; j < 10; j++){
			if (i - F[j] >= 0){
				dp[i] = (dp[i] + dp[i - F[j]]) % mod;
			}
		}
	}
	dp[0] = 0;
	dp[6]++;

	int t;
	while (scanf("%d", &t) == 1){

		while (t--){
			int n;
			scanf("%d", &n);
			printf("%d\n", dp[n]);
		}

	}
}