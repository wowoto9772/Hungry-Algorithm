#include <stdio.h>
#include <memory.h>

#define MinV -2000000003
#define m 3

int I[1000][3];
int dp[1000][3][8][1001];
int n;

int Max(int a, int b){ return a < b ? b : a; }

int dy(int r, int c, int s, int k){

	if (!k)return 0;
	else if (r == n){
		return MinV;
	}else if (c == m){
		return dy(r + 1, 0, s, k);
	}

	if (dp[r][c][s][k] != -1)return dp[r][c][s][k];

	dp[r][c][s][k] = MinV;

	if (s & 1){
		// already exists
		dp[r][c][s][k] = dy(r, c + 1, s >> 1, k);
	}
	else{

		if (c < m - 1 && !(s & 2)){ // horizontal
			dp[r][c][s][k] = Max(dp[r][c][s][k], I[r][c] + I[r][c + 1] + dy(r, c + 2, s >> 2, k - 1));
		}

		if (r < n - 1){ // vertical
			dp[r][c][s][k] = Max(dp[r][c][s][k], I[r][c] + I[r + 1][c] + dy(r, c + 1, (s >> 1) | (1 << (m - 1)), k - 1));
		}

		// pass
		dp[r][c][s][k] = Max(dp[r][c][s][k], dy(r, c + 1, s >> 1, k));

	}


	return dp[r][c][s][k];
}

int main(){

	int k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)scanf("%d", &I[i][j]);
	}

	for (int r = 0; r < n; r++){
		for (int c = 0; c < m; c++){
			for (int s = 0; s < 8; s++){
				for (int k_ = 1; k_ <= k; k_++){
					dp[r][c][s][k_] = -1;
				}
			}
		}
	}

	printf("%d\n", dy(0, 0, 0, k));

}