#include <stdio.h>
#include <memory.h>
#include <string.h>

int dp[35][2][5][5][5][5][5][5];
char str[35];

int dy(int c, int w, int n1, int n2, int n3, int n4, int n5, int n6){
	// num c : w's turn : 
	if (c == 31){
		return w; // win is w
	}

	if (dp[c][w][n1][n2][n3][n4][n5][n6] != -1)return dp[c][w][n1][n2][n3][n4][n5][n6];

	int N[7] = { 0 };
	N[1] = n1, N[2] = n2, N[3] = n3, N[4] = n4, N[5] = n5, N[6] = n6;

	dp[c][w][n1][n2][n3][n4][n5][n6] = w; // assume that w is win

	bool f = false;

	for (int i = 6; i >= 1; i--){
		if (c + i <= 31 && N[i] < 4){
			int d[7] = { 0 };
			d[i] = 1;
			f = true;
			dp[c][w][n1][n2][n3][n4][n5][n6] = dy(c + i, !w, n1 + d[1], n2 + d[2], n3 + d[3], n4 + d[4], n5 + d[5], n6 + d[6]);
			if (dp[c][w][n1][n2][n3][n4][n5][n6] == !w)return dp[c][w][n1][n2][n3][n4][n5][n6];
			// w is lose, but this is !w's optimal selection
		}
	}

	if (!f)dp[c][w][n1][n2][n3][n4][n5][n6] = w; // w is win

	return dp[c][w][n1][n2][n3][n4][n5][n6];
}

int main()
{
	while (scanf("%s", str) == 1){
		memset(dp, 0xff, sizeof(dp));
		int s = strlen(str);

		for (int i = 0; i < s; i++)if (str[i] == '0')return 0;

		int k = 0;

		int d[7] = { 0 };

		for (int i = 0; i < s; i++){
			int a = str[i] - '0';
			k += a;
			d[a]++;
		}

		int w = s % 2;
		// 0 : B , 1 : A
		int x = dy(k, w, d[1], d[2], d[3], d[4], d[5], d[6]);
		printf("%s %c\n", str, x == 1 ? 'A' : 'B');
	}
}

/*
11112226662 30 : 1 

356656
ABABAB

35665
ABABA

*/

/*
	27 1 A[][][][][][]
	*/
