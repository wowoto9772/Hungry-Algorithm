#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int dp[505][505];
int s[505];

int dy(int i, int j){
	int cst = s[j] - s[i - 1];
	if (i >= j)return 0;
	if (i + 1 == j)return cst;

	if (dp[i][j] != -1)return dp[i][j];

	dp[i][j] = INT_MAX;

	for (int a = i; a <= j; a++){

		dp[i][j] = min(dp[i][j], cst + dy(i, a) + dy(a + 1, j));

	}

	return dp[i][j];
}

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int k;
		scanf("%d", &k);

		for (int i = 1; i <= k; i++){
			for (int j = i; j <= k; j++){
				dp[i][j] = -1;
			}
		}

		for (int i = 1; i <= k; i++){
			int a;
			scanf("%d", &a);
			s[i] = s[i - 1] + a;
		}

		printf("%d\n", dy(1, k));

	}

}