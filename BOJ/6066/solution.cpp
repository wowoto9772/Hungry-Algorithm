#include <stdio.h>
#include <limits.h>

#include <algorithm>

using namespace std;

int dp[100003];

int p[103], c[103];

int main(){

	int n, h;
	scanf("%d %d", &n, &h);

	for(int i=1; i<=n; i++){
		scanf("%d %d", &p[i], &c[i]);
	}

	for(int i=1; i<=100000; i++){
		dp[i] = INT_MAX;
		for(int j=1; j<=n; j++){
			if(i - p[j] >= 0){
				if(dp[i-p[j]] != INT_MAX){
					dp[i] = min(dp[i-p[j]] + c[j], dp[i]);
				}
			}
		}
	}

	int ans = INT_MAX;

	for(int i=h; i<=100000; i++){
		ans = min(ans, dp[i]);
	}

	printf("%d\n", ans);

}
