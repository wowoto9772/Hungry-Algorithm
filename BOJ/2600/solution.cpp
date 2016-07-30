#include <stdio.h>
#include <memory.h>

int dp[503][503][2];

int a, b, c;

int dy(int x, int y, int k){

	if (dp[x][y][k] != -1)return dp[x][y][k];

	dp[x][y][k] = !k;

	if (x >= c){
		dp[x][y][k] = dy(x - c, y, !k);
	}

	if (dp[x][y][k] == k)return dp[x][y][k];

	if (y >= c){
		dp[x][y][k] = dy(x, y - c, !k);
	}
	
	if (dp[x][y][k] == k)return dp[x][y][k];

	if (x >= b){
		dp[x][y][k] = dy(x - b, y, !k);
	}

	if (dp[x][y][k] == k)return dp[x][y][k];

	if (y >= b){
		dp[x][y][k] = dy(x, y - b, !k);
	}

	if (dp[x][y][k] == k)return dp[x][y][k];

	if (x >= a){
		dp[x][y][k] = dy(x - a, y, !k);
	}

	if (dp[x][y][k] == k)return dp[x][y][k];

	if (y >= a){
		dp[x][y][k] = dy(x, y - a, !k);
	}

	if (dp[x][y][k] == k)return dp[x][y][k];

	return dp[x][y][k];

}

int main(){
	scanf("%d %d %d", &a, &b, &c);

	memset(dp, 0xff, sizeof(dp));

	for (int i = 1; i <= 5; i++){

		int x, y;
		scanf("%d %d", &x, &y);

		if (dy(x, y, 1) == 1)printf("A\n");
		else
			printf("B\n");

	}
}