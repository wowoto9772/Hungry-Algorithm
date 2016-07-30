#include <stdio.h>
#include <memory.h>
#define max 1000000009
int dp[100003];
long long s[100003];
int n;

int dy(int c){
	if (c == n + 1)return 1;

	dp[c] = 0;
	for (int i = n; i >= c; i--){
		if (s[i] - s[c - 1] >= 0){
			dp[c] += dy(i + 1);
			if (dp[c] >= max)dp[c] -= max;
		}
	}

	return dp[c];
}

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
		s[i] += s[i - 1];
	}

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(1));
}