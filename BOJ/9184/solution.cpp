#include <stdio.h>
#include <memory.h>

int dp[21][21][21];

int dy(int a, int b, int c){
	if (a <= 0 || b <= 0 || c <= 0)return 1;
	if (a > 20 || b > 20 || c > 20)return dy(20, 20, 20);

	if (dp[a][b][c] != -1)return dp[a][b][c];
	if (a < b && b < c)return dp[a][b][c] = dy(a, b, c - 1) + dy(a, b - 1, c - 1) - dy(a, b - 1, c);
	else
		return dp[a][b][c] = dy(a - 1, b, c) + dy(a - 1, b - 1, c) + dy(a - 1, b, c - 1) - dy(a - 1, b - 1, c - 1);
}

int main(){
	memset(dp, 0xff, sizeof(dp));

	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) == 3){
		if (a == -1 && b == -1 && c == -1)break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, dy(a, b, c));
	}
}