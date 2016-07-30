#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[2][1000003];

int main(){

	int n;
	scanf("%d", &n);

	memset(dp, 0xff, sizeof(dp));
	dp[0][500000] = 0;

	int ans = 0;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		int c = i % 2;
		for (int j = 0; j <= 1000000; j++){
			dp[!c][j] = max(dp[!c][j], dp[c][j]); // ignore
			if (dp[c][j] != -1){
				dp[!c][j + a] = max(dp[!c][j + a], dp[c][j] + a); // me
				dp[!c][j - a] = max(dp[!c][j - a], dp[c][j]); // you
			}
		}
		ans = max(ans, dp[!c][500000]);
	}

	printf("%d\n", ans ? ans : -1);

}