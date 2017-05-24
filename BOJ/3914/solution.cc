#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1003][2];

int main(){
	
	int n;
	scanf("%d", &n);

	int ans = 0;

	for (int i = 0; i < n; i++){
		int p = i & 1;
		int q = 1 ^ p;
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= c; j++){
			int v;
			scanf("%d", &v);
			for (int k = v; k >= 1; k--){
				dp[v][q] = max(dp[k][p] + v, dp[v][q]);
			}
		}
		for (int k = 1; k <= 1000; k++)dp[k][q] = max(dp[k][q], dp[k][p]);
	}

	for (int i = 1; i <= 1000; i++)ans = max(ans, dp[i][n&1]);
	printf("%d\n", ans);

}