#include <stdio.h>
#include <memory.h>
#include <map>

using namespace std;

#define max 1000000009
int dp[1000003];

int main(){

	int c[22][22] = { 0 }; // combination
	for (int i = 1; i <= 21; i++){
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int h, n;
		scanf("%d %d", &h, &n);
		h--;

		if (h <= 20){
			int minimum = 1 << h;
			if (n >= minimum){ // minimum value is 1 << m-1
				n -= minimum;
				dp[0] = 1;
				for (int i = 0; i <= h; i++){ // height
					for (int j = c[n][i]; j <= n; j++){
						dp[j] += dp[j - c[n][i]];
						if (dp[j] >= max)dp[j] %= max;
					}
					if (i == 0)dp[0]--;
				} // all value is setted minimum value. and plus !
				printf("%d\n", dp[n]);
				memset(dp, 0, sizeof(int) * n);
			}
			else{
				printf("0\n");
			}
		}
		else{
			printf("0\n");
		}
	}
}

/*
	1<<20 : 1048576
	1<<21 : 2097152
*/