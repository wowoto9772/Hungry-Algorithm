#include <stdio.h>
#include <memory.h>


int dp[1 << 11];
int dr[] = { -1, 0, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0, 0 };
int min(int a, int b){ return a < b ? a : b; }

int dy(int s){
	if (dp[s] != -1)return dp[s];

	dp[s] = 1 << 12;
	int stb[5][5] = { 0 };

	for (int i = 0; i < 9; i++){
		int k = (1 << i);
		if (k & s){
			stb[i / 3][i % 3] = 1;
		}
		else{
			stb[i / 3][i % 3] = 0;
		}
	}

	int tmp[5][5] = { 0 };
	for (int i = 0; i < 9; i++){

		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 3; k++){
				tmp[j][k] = stb[j][k];
			}
		}

		for (int j = 0; j < 5; j++){
			int ni = i / 3 + dr[j];
			int nj = i % 3 + dc[j];
			if (ni < 0 || nj < 0)continue;
			if (ni > 2 || nj > 2)continue;
			tmp[ni][nj] = !tmp[ni][nj];
		}
		int ns = 0;

		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 3; k++){
				ns |= (tmp[j][k] << (j * 3 + k));
			}
		}

		dp[s] = min(dp[s], dy(ns) + 1);
	}

	return dp[s];
}
int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int s = 0;
		char sstr[5] = { 0 };
		for (int i = 0; i < 3; i++){
			scanf("%s", sstr);
			for (int j = 0; j < 3; j++){
				if (sstr[j] == '*')s |= (1 << (3 * i + j));
			}
		}

		memset(dp, 0xff, sizeof(dp));
		dp[0] = 0;

		printf("%d\n", dy(s));
	}
}