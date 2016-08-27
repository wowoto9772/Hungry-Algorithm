#include <stdio.h>
#include <algorithm>

using namespace std;

long long dp[2003][13];

int main(){

	for(int i=1; i<=2000; i++){
		for(int k=1; k<=min(i, 9); k++){
			if(k == 1)dp[i][k] = 1LL;
			for(int j=(i<<1); j<=2000; j++){
				dp[j][k+1] += dp[i][k];
			}
		}
	}

	int t;
	scanf("%d", &t);

	while(t--){

		int m, n;

		scanf("%d %d", &m, &n);

		long long ans = 0;
		
		for(int i=(1<<(m-1)); i<=n; i++){
			ans += dp[i][m];
		}

		printf("%lld\n", ans);

	}

}
