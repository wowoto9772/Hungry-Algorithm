#include <stdio.h>
#include <limits.h>
#include <memory.h>

int abs(int a){ return a < -a ? -a : a; }
int min(int a, int b){ return a < b ? a : b; }

class ele{
public:
	int x, t;
}I[41];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n){
		for (int i = 1; i <= n; i++){ // if i<j then t_i < t_j
			scanf("%d %d", &I[i].x, &I[i].t);
		}

		int dp[43][4];
		int d[43][4];
		memset(dp, 0x2f, sizeof(dp));
		memset(d, 0x2f, sizeof(d));
		dp[0][1] = d[0][1] = 0;

		bool ng = false;

		for (int i = 1; i <= n+1; i++){
			// go home
			int j = i - 1;
			int ret = I[j].x, cst = I[i].x;
			bool flag = false;
			if (i == n + 1){
				cst = 0;
				I[i].t = INT_MAX;
			}
			if (dp[j][1] + ret * 2 + cst <= I[i].t){
				dp[i][0] = dp[j][1] + ret * 2;
				d[i][0] = min(d[i][0], d[j][1] + ret);
				flag = true;
			}
			if (dp[j][2] + ret * 3 + cst <= I[i].t){
				dp[i][0] = dp[j][2] + ret * 3;
				d[i][0] = min(d[i][0], d[j][2] + ret);
				flag = true;
			}
			if (dp[j][3] + ret * 4 + cst <= I[i].t){
				dp[i][0] = dp[j][3] + ret * 4;
				d[i][0] = min(d[i][0], d[j][3] + ret);
				flag = true;
			}
			if (i == n + 1)break;

			cst = abs(I[i].x - I[j].x);

			if (flag){
				dp[i][1] = I[i].t;
				d[i][1] = d[i][0] + I[i].x;
			}

			if (dp[j][1] + cst * 2 <= I[i].t && i >= 2){ // load 2
				dp[i][2] = I[i].t;
				d[i][2] = d[j][1] + cst;
				flag = true;
			}

			if (dp[j][2] + cst * 3 <= I[i].t && i >= 3){ // load 3
				dp[i][3] = I[i].t;
				d[i][3] = d[j][2] + cst;
				flag = true;
			}

			if (!flag){
				ng = true;
				printf("NG %d\n", i);
				break;
			}
		}

		// n+1 0
		if(!ng)printf("OK %d\n", d[n + 1][0]);
	}
}
