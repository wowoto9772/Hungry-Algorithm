#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int dr[] = { 0, 0, -1, 1, 0 };
int dc[] = { -1, 1, 0, 0, 0 };

int dp[1 << 9];

char str[5][5];

int goal;

int STN(char a[][5]){
	int k = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			int l = i * 3 + j;
			k |= (a[i][j] == '*') ? (1 << l) : 0;
		}
	}return k;
}

int ATN(int a[][5]){
	int k = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			int l = i * 3 + j;
			k |= (a[i][j]) ? (1 << l) : 0;
		}
	}return k;
}


int dy(int x){

	if (dp[x] != -1)return dp[x];

	int stb[5][5] = { 0 };
	for (int i = 0; i < 9; i++){
		if (x & (1 << i)){
			stb[i / 3][i % 3] = 1;
		}
		else{
			stb[i / 3][i % 3] = 0;
		}
	}

	dp[x] = 1 << 15;

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			
			int tmp[5][5] = { 0 };
			for (int a = 0; a < 3; a++)for (int b = 0; b < 3; b++)tmp[a][b] = stb[a][b];
			
			for (int k = 0; k < 5; k++){
				int ni = i + dr[k];
				int nj = j + dc[k];
				if (ni < 0 || ni >= 3 || nj < 0 || nj >= 3)continue;
				tmp[ni][nj] ^= 1;
			}

			int nx = ATN(tmp);

			dp[x] = min(dp[x], dy(nx) + 1);

		}
	}


	return dp[x];

}

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		for (int i = 0; i < 3; i++)scanf("%s", str[i]);
		for (int i = 0; i < (1 << 9); i++)dp[i] = -1;
		goal = STN(str);
		dp[goal] = 0;
		printf("%d\n", dy(0));

	}

}
