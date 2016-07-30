#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define MV 987654321

using namespace std;

int I[13][13];
int dp[1 << 10][10] = { 0 };
int n, snk, src;

int F(int S, int V) {

	if (dp[S][V] != -1)return dp[S][V];

	dp[S][V] = MV;

	if (S == snk) {
		if (I[V][src])dp[S][V] = I[V][src];
	}
	else {

		for (int i = 0; i < n; i++) {
			if (I[V][i] && (S | (1 << i)) != S) { // check 되있으면서, 방문하지 않은곳
				dp[S][V] = min(dp[S][V], F(S | (1 << i), i) + I[V][i]);
			}
		}
	}

	return dp[S][V];
}

int main()
{

	scanf("%d", &n);
	snk = (1 << n) - 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &I[i][j]);
		}
	}

	int ans = MV;

	for (int i = 0; i < n; i++) {

		memset(dp, 0xff, sizeof(dp));

		src = i;

		int tmp = F(1 << i, i);

		if (ans > tmp)ans = tmp;

		break;

	} 
	
	// wherever, the minimum distance are same.

	// 1 2 3 4 1
	// 2 3 4 1 2
	// 3 4 1 2 3
	// 4 1 2 3 4 

	if (ans == MV)ans = -1;

	printf("%d\n", ans);

}