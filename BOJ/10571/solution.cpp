#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[202];
double w[202], c[202];

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++){
			scanf("%lf %lf", &w[i], &c[i]);
			dp[i] = 1;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++){

			for (int j = 1; j < i; j++){
				if (w[i] > w[j] && c[i] < c[j]){
					dp[i] = max(dp[j] + 1, dp[i]);
				}
			}

			ans = max(ans, dp[i]);
		}

		printf("%d\n", ans);
	}

}