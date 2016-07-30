//#include <stdio.h>
//#include <memory.h>
//
//int p[303];
//int dp[303][33];
//int s[303];
//int min(int a, int b){ return a < b ? a : b; }
//
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	memset(dp, 0x2f, sizeof(dp));
//
//	int l = 0, r;
//	for (int i = 1; i <= n; i++){
//		scanf("%d", &p[i]);
//		s[i] = s[i - 1] + p[i];
//		dp[i][1] = i * p[i] - (s[i] - s[0]);
//	}
//
//
//	for (int i = 1; i <= n; i++){
//		dp[i - 1][0] = 0;
//		for (int k = 1; k <= i && k <= m; k++)
//		{
//			//if (k != 1)
//			{
//				for (int j = i - 1; j >= k - 1; j--){
//					dp[i][k] = min(dp[i][k], dp[j][k - 1] + p[i] * (i - j - 1) - (s[i - 1] - s[j]));
//				}
//			}
//			for (int j = i + 1; j <= n; j++){
//				//dp[j][k] = min(dp[j][k], dp[i][k] + (s[j] - s[i]) - p[i] * (j - i));
//			}
//		}
//	}
//
//	printf("%d\n", dp[n][m]);
//}

#include <stdio.h>
#include <memory.h>
#define min(a, b) (a) < (b) ? (a) : (b)

int dp[303][33];
int p[303], s[303];
int x[303][303];

int main()
{

	memset(dp, 0x2f, sizeof(dp));

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
		s[i] = s[i - 1] + p[i];
	}

	memset(x, 0x2f, sizeof(x));

	for (int i = 1; i <= n; i++){ // interval start
		for (int j = i; j <= n; j++){ // interval end
			for (int y = i; y <= j; y++){ // post office
				int left = p[y] * (y - i + 1) - (s[y] - s[i - 1]);
				int right = s[j] - s[y] - p[y] * (j - y);
				x[i][j] = min(x[i][j], left + right);
			}
		}
	}

	dp[0][0] = 0;
	for (int k = 1; k <= m; k++){
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
				dp[j][k] = min(dp[j][k], dp[i-1][k-1] + x[i][j]);
			}
		}
	}

	printf("%d\n", dp[n][m]);
}