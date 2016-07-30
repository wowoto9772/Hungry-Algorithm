#include <stdio.h>

#include <algorithm>

using namespace std;

char S[10003], E[10003];

int dp[10003][13];
int nxt[10003][13];

int n;

int dy(int c, int le) {
	
	if (c == n)return 0;

	if (dp[c][le] != -1)return dp[c][le];	
	
	int L = E[c] - ((S[c] + le - '0') % 10 + '0');
	if (L < 0)L += 10;

	int R = 10 - L;

	int goLe = L + dy(c + 1, (le + L) % 10);
	int goRi = R + dy(c + 1, le);

	if (goLe > goRi) {
		dp[c][le] = goRi;
		nxt[c][le] = -R;
	}
	else {
		dp[c][le] = goLe;
		nxt[c][le] = L;
	}

	return dp[c][le];

}
int main()
{
	scanf("%d", &n);

	scanf("%s %s", S, E);

	for (int i = 0; i < n; i++)for (int j = 0; j < 10; j++)dp[i][j] = -1;

	printf("%d\n", dy(0, 0));

	int c = 0;

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", i+1, nxt[i][c]);
		if(nxt[i][c] > 0)c += nxt[i][c];
		if (c < 0)c += 10;
		c %= 10;
	}

}