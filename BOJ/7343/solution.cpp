#include <stdio.h>
#include <memory.h>

int M[13][2] = { { 0, 0 }, { 31, 31 }, { 28, 29 }, { 31, 31 }, { 30, 30 }, { 31, 31 }, { 30, 30 }, { 31, 31 }, { 31, 31 }, { 30, 30 }, { 31, 31 }, { 30, 30 }, { 31, 31 } };
int dp[2009][14][33][2];

bool Eun(int a){
	if (a % 400 == 0)return true;
	else if (a % 100 == 0)return false;
	else if (a % 4 == 0)return true;
	else
		return false;
}

int dy(int y, int m, int d, int w){
	if (y == 2001){
		if (m == 11){
			if (d == 4)return dp[y][m][d][w] = w;
			else if (d > 4)return !w;
		}
		else if (m > 11)return !w;
	}
	else if (y > 2001)return !w;

	if (dp[y][m][d][w] != -1)return dp[y][m][d][w];

	dp[y][m][d][w] = w;

	int eun = Eun(y);
	if (m == 12){
		if (d <= M[1][eun]){
			dp[y][m][d][w] = dy(y + 1, 1, d, !w);
		}
		if (dp[y][m][d][w] == w){
			int nd = d + 1;
			if (d <= M[m][eun]){
				dp[y][m][d][w] = dy(y, m, nd, !w);
			}
			else{
				dp[y][m][d][w] = dy(y + 1, 1, 1, !w);
			}
		}
	}
	else{
		if (d <= M[m + 1][eun]){
			dp[y][m][d][w] = dy(y, m + 1, d, !w);
		}
		if (dp[y][m][d][w] == w){
			int nd = d + 1;
			if (nd <= M[m][eun]){
				dp[y][m][d][w] = dy(y, m, nd, !w);
			}
			else{
				dp[y][m][d][w] = dy(y, m + 1, 1, !w);
			}
		}
	}

	return dp[y][m][d][w];
}

int main(){
	memset(dp, 0xff, sizeof(dp));

	int t;
	scanf("%d", &t);

	while (t--){
		int y, m, d;
		scanf("%d %d %d", &y, &m, &d);

		if (dy(y, m, d, 1) == 0)printf("YES\n");
		else
			printf("NO\n");
	}
}