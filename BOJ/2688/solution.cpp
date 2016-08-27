#include <stdio.h>

long long dp[66][10];

int main(){

	for(int i=0; i<10; i++)dp[1][i] = 1;

	for(int i=0; i<=63; i++){
		for(int j=0; j<10; j++){
			for(int k=j; k<10; k++){
				dp[i+1][k] += dp[i][j];
			}
		}
	}

	int t;
	scanf("%d", &t);

	while(t--){

		int n;
		scanf("%d", &n);

		long long ans = 0;

		for(int i=0; i<10; i++)ans += dp[n][i];

		printf("%lld\n", ans);

	}

}
