#include <stdio.h>

#define MID (2500 * 1000)

int dp[53][53];

int cnt[MID * 2 + 3];

int Sum(int a, int b, int i, int j){
	return dp[i][j] - dp[a - 1][j] - dp[i][b-1] + dp[a - 1][b - 1];
}

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int a;
			scanf("%d", &a);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){

			for (int a = 1; a <= i; a++){
				for (int b = 1; b <= j; b++){
					cnt[Sum(a, b, i, j) + MID]++;
				}
			}

			for (int a = i + 1; a <= n; a++){
				for (int b = j + 1; b <= n; b++){
					ans += cnt[Sum(i+1, j+1, a, b) + MID];
				}
			}

			for (int a = 1; a <= i; a++){
				for (int b = 1; b <= j; b++){
					cnt[Sum(a, b, i, j) + MID]--;
				}
			}

			for (int a = 1; a <= i; a++){
				for (int b = j; b <= n; b++){
					cnt[Sum(a, j, i, b) + MID]++;
				}
			}

			for (int a = i + 1; a <= n; a++){
				for (int b = 1; b < j; b++){
					ans += cnt[Sum(i+1, b, a, j-1) + MID];
				}
			}

			for (int a = 1; a <= i; a++){
				for (int b = j; b <= n; b++){
					cnt[Sum(a, j, i, b) + MID]--;
				}
			}


			// 또, 경쟁심을 유도하기위해 두 땅은 꼭지점 하나에서만 만나게 하려고 한다.
		}
	}

	printf("%d\n", ans);
}