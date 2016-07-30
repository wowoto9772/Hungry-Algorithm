#include <stdio.h>
#include <memory.h>

int S[402];
int dp[402][402][52];

int ab(int a){ return a < -a ? -a : a; }
int M(int a, int b){ return a < b ? b : a; }

int N, K;

int main()
{
	freopen("large_dat4.in", "r", stdin);
	freopen("large_dat4.out", "w", stdout);

	while (scanf("%d %d", &N, &K) == 2){

		for (int i = 1; i <= N; i++){
			scanf("%d", &S[i]);
			S[i] += S[i - 1];
		}

		int ans = 0;
		memset(dp, 0xff, sizeof(dp));

		for (int i = 0; i <= N - (K - 1); i++)
			for (int j = i + 1; j <= N - (K - 1); j++)
				dp[i][j][1] = 0;

		for (int k = 1; k < K; k++){
			for (int a = 0; a <= N - (K - k) - 1; a++){
				for (int b = a + 1; b <= N - (K - k); b++){
					for (int c = b + 1; c <= N - (K - (k + 1)); c++){
						if (dp[a][b][k] > -1){
							int x = dp[a][b][k] + ab((S[b] - S[a]) - (S[c] - S[b]));
							if (dp[b][c][k + 1] < x)dp[b][c][k + 1] = x;
							if (ans < dp[b][c][K])ans = dp[b][c][K];
						}
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}