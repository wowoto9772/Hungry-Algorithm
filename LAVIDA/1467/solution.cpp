#include <stdio.h>
#include <limits.h>

double dp[10000003];

int main()
{
	for (int i = 1; i <= 4; i++)dp[i] = 10;
	for (int i = 5; i <= 8; i++)dp[i] = 10 + (i - 4) * 2;
	for (int i = 9; i <= 12; i++)dp[i] = 18 + (i - 8) * 2.4;

	for (int i = 13; i <= 10000000; i++){
		dp[i] = dp[i - 8] + 18.0;
	}

	int n;
	while (scanf("%d", &n) == 1 && n){
		int x = dp[n] * 10; 
		if (x%10)printf("%.1lf\n", dp[n]);
		else{
			printf("%d\n", (int)dp[n]);
		}
	}
}