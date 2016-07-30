#include <stdio.h>
#include <string.h>
#include <memory.h>
#define ll long long

ll dp[103][103];

int g[103][3];
char str[103];

int s;

ll dy(int p, int r){

	if (dp[p][r] != -1)return dp[p][r];

	dp[p][r] = 0;

	if (p == s){
		if (!r){
			dp[p][r]++;
		}
	}
	else{
		for (int j = 3; r && p + j - 1 < s; j += 3){
			if (p){
				int k = g[j + p - 1][0] - g[p - 1][0];
				if (k == g[j + p - 1][1] - g[p - 1][1] && k == g[j + p - 1][2] - g[p - 1][2]){
					dp[p][r] += dy(p + j, r - 1);
				}
			}
			else{
				int k = g[j + p - 1][0];
				if (k == g[j + p - 1][1] && k == g[j + p - 1][2]){
					dp[p][r] += dy(p + j, r - 1);
				}
			}
		}
	}

	return dp[p][r];
}

int main(){

	int n;
	while (scanf("%d", &n) == 1){

		scanf("%s", str);

		s = strlen(str);

		if (s % 3)printf("Impossible\n");
		else{

			for (int i = 0; i < s; i++){
				if (i)g[i][0] = g[i - 1][0], g[i][1] = g[i - 1][1], g[i][2] = g[i - 1][2];
				else{
					g[0][0] = g[0][1] = g[0][2] = 0;
				}

				if (str[i] == 'B'){
					g[i][0]++;
				}
				else if (str[i] == 'F'){
					g[i][1]++;
				}
				else{ // S
					g[i][2]++;
				}
			}

			memset(dp, 0xff, sizeof(dp));

			if (dy(0, n))printf("%lld\n", dy(0, n));
			else
				printf("Impossible\n");

		}

	}

}