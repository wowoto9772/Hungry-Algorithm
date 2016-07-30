#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[103][103];
char str[103];

int main(){
	for (int i = 0; i < 100; i++){
		for (int j = i; j >= 0; j--){
			dp[i][j] = -1;
		}
	}

	while (scanf("%s", str) == 1 && strcmp(str, "end")){
		int s = strlen(str);

		for (int i = 0; i < s; i++){
			for (int j = i + 1; j < s; j++){
				if (str[i] == '(' && str[j] == ')')dp[i][j] = 2;
				else if (str[i] == '[' && str[j] == ']')dp[i][j] = 2;
				else{
					dp[i][j] = 0;
				}
			}
		}

		int ans = 0;

		for (int k = 1; k < s; k++){
			for (int i = 0; i + k < s; i++){
				int j = i + k;
				for (int l = i; l < j; l++){
					dp[i][j] = max(dp[i][j], dp[i][l] + dp[l + 1][j]);
				}
				dp[i][j] = max(dp[i][j], max(dp[i+1][j], dp[i][j-1]));
				
				int p = 0;
				if (str[i] == '(' && str[j] == ')')p = 2;
				else if (str[i] == '[' && str[j] == ']')p = 2;
				dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + p);
				ans = max(ans, dp[i][j]);
			}
		}

		printf("%d\n", ans);
	}
}