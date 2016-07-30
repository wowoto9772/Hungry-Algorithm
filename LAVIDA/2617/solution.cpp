#include <stdio.h>
#include <string.h>
#include <memory.h>

char C[103], S[103], J[103];
int c, s, j;
int dp[103][103][103];

int M(int a, int b){ return a < b ? b : a; }

int dy(int x, int y, int z){
	if (!x || !y || !z)return 0;
	if (dp[x][y][z] != -1)return dp[x][y][z];

	if (C[x] == S[y] && S[y] == J[z]){
		dp[x][y][z] = 1 + dy(x - 1, y - 1, z - 1);
	}
	else{
		dp[x][y][z] = M(dy(x - 1, y, z), M(dy(x, y - 1, z), dy(x, y, z - 1)));
	}

	return dp[x][y][z];
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s %s %s", C + 1, S + 1, J + 1);
		c = strlen(C + 1), s = strlen(S + 1), j = strlen(J + 1);

		memset(dp, 0xff, sizeof(dp));

		printf("%d\n", dy(c, s, j));
	}
}