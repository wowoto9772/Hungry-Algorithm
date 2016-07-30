#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k;
int dp[50003][4];

int p[50003];
int s[50003];

int dy(int cur, int cnt){
	if (cnt >= 3)return 0;
	if (cur > n)return 0;
	if (dp[cur][cnt] != -1)return dp[cur][cnt];

	dp[cur][cnt] = 0;
	if (cur + k - 1 <= n && cnt <= 2){
		dp[cur][cnt] = max(dp[cur][cnt], s[cur + k - 1] - s[cur - 1] + dy(cur + k, cnt + 1));
	}
	dp[cur][cnt] = max(dp[cur][cnt], dy(cur + 1, cnt));

	return dp[cur][cnt];

}

int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
		s[i] = s[i - 1] + p[i];
		for (int k = 0; k <= 3; k++){
			dp[i][k] = -1;
		}
	}

	dp[0][0] = -1;

	scanf("%d", &k);

	printf("%d\n", dy(1, 0));

}