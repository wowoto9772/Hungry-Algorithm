#include <stdio.h>
#include <algorithm>

using namespace std;

int w[13];
int dp[10][21][1 << 13];

int n, m, c;

int dy(int cur, int cap, int pick){
	if (cur == m)return 0;
	if (dp[cur][cap][pick] != -1)return dp[cur][cap][pick];

	dp[cur][cap][pick] = dy(cur + 1, c, pick); // use next bag

	for (int i = 0; i < n; i++){
		int none = (1 << i);
		if (pick & none)continue;
		if (cap >= w[i]){
			// fill current bag if possible
			dp[cur][cap][pick] = max(dp[cur][cap][pick], 1 + dy(cur, cap - w[i], pick | none));
		}
	}

	return dp[cur][cap][pick];
}

int main(){

	scanf("%d %d %d", &n, &m, &c);

	for (int i = 0; i < n; i++){
		scanf("%d", &w[i]);
	}

	for (int i = 0; i < m; i++)for (int j = 0; j <= c; j++)for (int k = 0; k < (1 << n); k++)dp[i][j][k] = -1;

	printf("%d\n", dy(0, c, 0));

}