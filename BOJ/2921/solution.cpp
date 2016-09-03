#include <stdio.h>

int dp[1003] = {0, 3};

int main(){

	int n;
	scanf("%d", &n);

	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1];
		for(int j=0; j<=i; j++){
			dp[i] += i + j;
		}
	}

	printf("%d\n", dp[n]);


}
