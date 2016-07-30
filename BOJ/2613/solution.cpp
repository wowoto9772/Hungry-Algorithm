#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int I[303];
int S[303];

int dp[303][303];
int rev[303][303];
int out[303];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		scanf("%d", &I[i]);
		S[i] = S[i - 1] + I[i];
	}

	if (m != 1){
		for (int i = 1; i < m; i++){
			for (int j = i; j <= n - m + i; j++){
				dp[j][i] = S[j];
				rev[j][i] = 0;
				if (i > 1){
					for (int k = i - 1; k < n - m + i; k++){
						int g = max(dp[k][i-1], S[j] - S[k]);
						if (dp[j][i] > g){
							dp[j][i] = g;
							rev[j][i] = k;
						}
					}
				}
			}
		}
		
		dp[n][m] = INT_MAX;

		for (int i = m; i <= n; i++){
			int tmp = max(dp[i - 1][m - 1], S[n] - S[i - 1]);
			if (dp[n][m] > tmp){
				dp[n][m] = tmp;
				rev[n][m] = i - 1;
			}
		}

		printf("%d\n", dp[n][m]);

		int top = 0;
		int c = m;

		int l = n;
		int r = n;

		while (l){
			r = l;
			l = rev[l][c];
			out[top++] = r - l;
			c--;
		}

		reverse(out, out + top);

		for (int i = 0; i < top; i++)printf("%d ", out[i]);
	}
	else{
		printf("%d\n%d", S[n], n);
	}
}