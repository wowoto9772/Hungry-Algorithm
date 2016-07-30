#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <algorithm>

using namespace std;

char a[3003], b[3003];

int sme, spc, dif;

int dp[3003][3003];

int dy(int x, int y) {

	if (x < 0 && y < 0)return 0;
	else if (x < 0)return ++y * spc;
	else if (y < 0)return ++x * spc;

	if (dp[x][y] != -1)return dp[x][y];

	if (a[x] == b[y])dp[x][y] = dy(x - 1, y - 1) + sme;
	else {
		dp[x][y] = dif + dy(x - 1, y - 1);
	}

	dp[x][y] = max(dp[x][y], spc + max(dy(x - 1, y), dy(x, y - 1)));


	return dp[x][y];

}

int main() {

	scanf("%d %d %d", &sme, &spc, &dif);
	
	scanf("%s %s", a, b);

	int sa = strlen(a), sb = strlen(b);

	for (int i = 0; i < sa; i++)for (int j = 0; j < sb; j++)dp[i][j] = -1;

	printf("%d\n", dy(sa - 1, sb - 1));

}