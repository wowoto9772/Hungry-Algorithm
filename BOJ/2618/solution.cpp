//#include <stdio.h>
//#include <limits.h> 
//#include <map>
//
//using namespace std;
//
//int x[1002] = { 1, }, y[1002] = { 1, };
//map <int, map<int, map<int, int> > > dp;
//
//int n;
//int A(int a){ return a < -a ? -a : a; }
//int min(int a, int b){ return a < b ? a : b; }
//int ans[1002];
//
//int dy(int f, int s, int k){
//	printf("%d %d %d\n", f, s, k);
//	if (k == n + 1)return 0;
//	if (dp[f][s].count(k) != 0)return dp[f][s][k];
//
//	dp[f][s][k] = INT_MAX;
//
//	int cmp = A(x[f] - x[k]) + A(y[f] - y[k]) + dy(k, s, k + 1);
//	if (dp[f][s][k] > cmp){
//		dp[f][s][k] = cmp;
//		ans[k] = 1;
//	}
//
//	cmp = A(x[s] - x[k]) + A(y[s] - y[k]) + dy(f, k, k + 1);
//	if (dp[f][s][k] > cmp){
//		dp[f][s][k] = cmp;
//		ans[k] = 2;
//	}
//
//	return dp[f][s][k];
//}
//
//int main(){
//	scanf("%d", &n);
//	int e = n;
//	scanf("%d", &n);
//	x[n+1] = y[n+1] = e;
//
//	for (int i = 1; i <= n; i++)scanf("%d %d", &x[i], &y[i]);
//	
//	printf("%d\n", dy(0, n+1, 1));
//	for (int i = 1; i <= n; i++)printf("%d\n", ans[i]);
//}

#include <stdio.h>
#include <limits.h>

int dp[1003][1003];
int r[1003][1003][2];
int x[1003] = { 1 }, y[1003] = { 1 };
int A(int a){ return a < -a ? -a : a; }

int main(){
	int n;
	scanf("%d", &n);

	x[1] = y[1] = n;
	scanf("%d", &n);

	for (int i = 2; i <= n + 1; i++)scanf("%d %d", &x[i], &y[i]);

	for (int i = 0; i <= n + 1; i++){
		for (int j = 0; j <= n + 1; j++){
			dp[i][j] = INT_MAX;
		}
	}
	dp[0][1] = 0;

	int ans = INT_MAX, a, b;
	for (int i = 0; i <= n + 1; i++){
		for (int j = 0; j <= n + 1; j++){
			if (dp[i][j] < INT_MAX){
				int M = i < j ? j : i;
				M++;
				if (M <= n + 1){
					int cst = dp[i][j] + A(x[j] - x[M]) + A(y[j] - y[M]);
					if (dp[i][M] > cst){
						dp[i][M] = cst;
						r[i][M][0] = i, r[i][M][1] = j;
					}

					cst = dp[i][j] + A(x[i] - x[M]) + A(y[i] - y[M]);
					if (dp[M][j] > cst){
						dp[M][j] = cst;
						r[M][j][0] = i, r[M][j][1] = j;
					}

					if (M == n + 1){
						if (dp[i][M] < dp[M][j]){
							if (ans > dp[i][M]){
								ans = dp[i][M];
								a = i, b = M;
							}
						}
						else{
							if (ans > dp[M][j]){
								ans = dp[M][j];
								a = M, b = j;
							}
						}
					}
				}
			}
		}
	}

	printf("%d\n", ans);

	int ans2[1003] = { 0 };

	while (true){
		int M = a < b ? b : a;
		if (a < b)ans2[M] = 2;
		else{
			ans2[M] = 1;
		}
		int na = r[a][b][0], nb = r[a][b][1];
		a = na;
		b = nb;

		if (M == 2)break;
	}

	for (int i = 2; i <= n + 1; i++)printf("%d\n", ans2[i]);
}