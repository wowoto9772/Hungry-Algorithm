#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1000003];

int main(){
	int n;
	scanf("%d", &n);

	int ans = n;

	for (int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);

		dp[a] = dp[a - 1] + 1;

		int tmp = n - dp[a];

		ans = min(ans, tmp);
	}

	printf("%d\n", ans);
}