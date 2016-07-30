#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1003];
int dp2[1003];
int a[1003];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++){
		dp[i] = a[i];
		dp2[i] = i;
		for (int j = 1; j < i; j++){
			if (a[dp2[j]] < a[dp2[i]]){
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);
}