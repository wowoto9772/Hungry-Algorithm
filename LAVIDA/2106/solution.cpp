#include <stdio.h>
#include <memory.h>
#define MAX 550

char I[8][13];
int dp[1 << 10][6][12];
int R, C;
int m(int a, int b){ return a < b ? a : b; }

int dy(int s, int r, int c){
	if (c >= C){
		return dy(s, r + 1, 0);
	}
	else if (r >= R){
		return 0;
	}
	if (dp[s][r][c] != -1)return dp[s][r][c];

	dp[s][r][c] = MAX;

	if (I[r][c] == '*'){
		int k = (1 << c);
		int a;
		if (R == 5){
			a = 0;
			for (int i = 0; i < 5; i++){
				if (I[i][c] == '*')a++;
				else
					break;
			}
			if (a == 5 && !(k & s)){
				dp[s][r][c] = m(dp[s][r][c], 1 + dy(s | k, r, c + 1));
			}
		}
		a = 0;
		for (int i = 0; i < 5; i++){
			if (c + i < C && I[r][c + i] == '*')a++;
			else{
				break;
			}
		}
		if (a >= 5)dp[s][r][c] = m(dp[s][r][c], 1 + dy(s, r, c + 5));
		else{
			int b = 0;
			for (int i = 1; i < 5; i++){
				if (c - i >= 0 && I[r][c - i] == '*')b++;
				else
					break;
			}
			if (a + b >= 5){
				dp[s][r][c] = m(dp[s][r][c], 1 + dy(s, r, c + a));
			}
		}
		if (k & s)dp[s][r][c] = m(dp[s][r][c], dy(s, r, c + 1));
	}
	else{
		dp[s][r][c] = dy(s, r, c + 1);
	}

	return dp[s][r][c];
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &R, &C);

		for (int i = 0; i < R; i++)scanf("%s", I[i]);

		memset(dp, 0xff, sizeof(dp));

		int a = dy(0, 0, 0);

		if (a == MAX)a = -1;

		printf("%d\n", a);
	}
}
