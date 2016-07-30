#include <stdio.h>
#define mid (n*1000)

bool dp[60005][2];

int main(){
	int n;
	scanf("%d", &n);

	dp[mid][0] = true;

	for (int i = 0; i < n; i++){
		int w;
		scanf("%d", &w);

		int c = i % 2;

		// state are saved.
		for (int j = 0; j <= 2 * mid; j++)dp[j][!c] = dp[j][c];

		for (int j = 0; j <= 2 * mid; j++){
			if (dp[j][c]){
				dp[j - w][!c] = true;
				dp[j + w][!c] = true;
			}
		}

		dp[mid + w][!c] = true;
	}

	int q;
	scanf("%d", &q);

	for (int i = 1; i <= q; i++){
		int a;
		scanf("%d", &a);
		printf("%c ", dp[mid + a][!((n - 1) % 2)] ? 'Y' : 'N');
	}
}