#include <stdio.h>
#include <algorithm>

using namespace std;

int p[1003];
int dp[1003];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &p[i]);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	printf("%d\n", dp[n]);
}