#include <stdio.h>

#include <limits.h>

#include <algorithm>

using namespace std;

int n, k;

int fac[2][100003];

int dp[2][100003];

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		scanf("%d %d", &n, &k);

		for(int i=1; i<=n; i++){

			int v;
			scanf("%d", &v);

			int j = v;

			fac[0][i] = fac[1][i] = 0;

			while(!(j&1)){
				j >>= 1;
				fac[0][i]++;
			}

			while(!(v%5)){
				v /= 5;
				fac[1][i]++;
			}

		}

		dp[0][1] = fac[0][1], dp[1][1] = fac[1][1];

		for(int i=2; i<=n; i++){

			dp[0][i] = dp[1][i] = INT_MAX;

			for(int j=i-1; j>=i-k && j>=1; j--){
				
				dp[0][i] = min(dp[0][i], dp[0][j] + fac[0][i]);
				dp[1][i] = min(dp[1][i], dp[1][j] + fac[1][i]);

			}
			
		}

		printf("%d\n", min(dp[0][n], dp[1][n]));

	}

}
