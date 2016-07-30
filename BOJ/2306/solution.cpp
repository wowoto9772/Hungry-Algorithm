#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[503];
int dp[503][503];

int dy(int le, int ri){
	if (le >= ri)return 0;
	if (dp[le][ri] != -1)return dp[le][ri];

	dp[le][ri] = max(dy(le, ri - 1), dy(le + 1, ri));

	if (str[le] == 'a' && str[ri] == 't' ||
		str[le] == 'g' && str[ri] == 'c'){
		dp[le][ri] = max(dp[le][ri], 2 + dy(le + 1, ri - 1));
	}

	for (int i = le; i <= ri; i++){
		dp[le][ri] = max(dp[le][ri], dy(le, i) + dy(i + 1, ri));
	}

	return dp[le][ri];

}

int main(){

	scanf("%s", str);

	int s = strlen(str);

	for (int i = 0; i < s; i++){
		for (int j = i; j < s; j++){
			dp[i][j] = -1;
			if (j == i + 1){
				if (str[i] == 'a' && str[j] == 't' ||
					str[i] == 'g' && str[j] == 'c'){
					dp[i][j] = 2;
				}
			}
		}
	}

	printf("%d\n", dy(0, s - 1));

}