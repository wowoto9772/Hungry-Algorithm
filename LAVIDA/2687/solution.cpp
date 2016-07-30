#include <stdio.h>
#include <memory.h>
#include <limits.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int dp[2][1 << 15];
int lst, n, p[17];

int dy(int d, int s){
	if (s == lst)return 0;
	if (dp[d][s] != -1)return dp[d][s];

	dp[d][s] = 5000 * 31;

	if (d){
		for (int i = 0; i < n; i++){
			if (s & (1 << i)){
				dp[d][s] = min(dp[d][s], p[i] + dy(0, s ^ (1 << i)));
			}
		}
	}
	else{
		for (int i = 0; i < n; i++){
			if (s & (1 << i))continue;
			for (int j = i + 1; j < n; j++){
				if (s & (1 << j))continue;
				dp[d][s] = min(dp[d][s], max(p[i], p[j]) + dy(1, s | (1 << i) + (1 << j)));
			}
		}
	}

	return dp[d][s];
}

int main(){
	scanf("%d", &n);

	lst = 1 << n;
	lst--;

	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		if (i >= 2)continue;
		for (int j = 0; j <= lst; j++){
			dp[i][j] = -1;
		}
	}

	printf("%d\n", dy(0, 0));
}