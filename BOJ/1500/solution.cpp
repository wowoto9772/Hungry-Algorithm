#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

ll dp[103][23];

ll dy(int s, int k){
	if (dp[s][k] != -1)return dp[s][k];

	dp[s][k] = 0;

	if (k - 1 >= 0){
		for (ll i = s - 1; i >= k - 1; i--){
			dp[s][k] = max(dp[s][k], (ll)(s - i) * dy(i, k - 1));
		}
	}

	return dp[s][k];
}

int main(){

	int s, k;
	scanf("%d %d", &s, &k);

	if (k == 0)printf("0\n");
	else {

		for (int i = 0; i <= s; i++)for (int j = 0; j <= k; j++)dp[i][j] = -1;

		dp[0][0] = 1LL;

		printf("%lld\n", dy(s, k));

	}
}
