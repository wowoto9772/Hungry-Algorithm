#include <stdio.h>
#include <string.h>
#include <string.h>

#define MAX 1503

char str[3][503];

int dx[3] = { 0, 1, -1 };
int dc[3] = { 0, 1, 1 };

int dp[3][503];
int m(int a, int b){ return a < b ? a : b; }

int main()
{
	int t;
	scanf("%d", &t);
	while (t--){
		for (int i = 0; i < 3; i++)scanf("%s", str[i]);
		int l = strlen(str[0]);

		memset(dp, 0x2f, sizeof(dp));
		dp[1][0] = 0;

		for (int i = 0; i < l-1; i++){
			for (int k = 0; k < 3; k++){
				if (str[k][i] == '.'){
					for (int j = 0; j < 3; j++){
						int nk = k + dx[j];
						if (nk >= 0 && nk < 3){
							if (str[nk][i + 1] == '.'){
								dp[nk][i + 1] = m(dp[nk][i + 1], dp[k][i] + dc[j]);
							}
						}
					}
				}
			}
		}

		int k = m(dp[0][l - 1], m(dp[1][l - 1], dp[2][l - 1]));
		int ans = k;
		if (ans >= MAX)ans = -1;

		printf("%d\n", ans);
	}
}