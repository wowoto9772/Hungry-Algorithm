#include <stdio.h>

int di[] = { 0, 0, -1, 1 };
int dj[] = { -1, 1, 0, 0 };

int dp[503][503];
int v[503][503];

int r, c;

int dy(int i, int j){
	if (i < 1 || i > r || j < 1 || j > c)return 0;
	if (dp[i][j] != -1)return dp[i][j];

	dp[i][j] = 0;
	for (int k = 0; k < 4; k++){
		int ni = i + di[k];
		int nj = j + dj[k];
		if (v[i][j] > v[ni][nj]){
			dp[i][j] += dy(ni, nj);
		}
	}

	return dp[i][j];

}

int main(){

	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++){
		scanf("%d", &v[i][j]);
		dp[i][j] = -1;
	}

	dp[r][c] = 1;

	printf("%d\n", dy(1, 1));

}