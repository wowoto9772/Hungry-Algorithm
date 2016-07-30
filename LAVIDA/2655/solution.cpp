//#include <stdio.h>
//#include <limits.h>
//
//int c[103];
//int dp[101003][2][2];
//
//int main(){
//	int n;
//	while (scanf("%d", &n) == 1 && n){
//		for (int i = 1; i <= n; i++)scanf("%d", &c[i]);
//
//		for (int i = 0; i <= n * 1000 + 1000; i++){
//			dp[i][0][0] = dp[i][1][0] = 0;
//			dp[i][0][1] = dp[i][1][1] = INT_MAX;
//		}
//
//		dp[0][0][1] = 0;
//
//		int mc = 0, f = 0; // max_change
//		for (int i = 1; i <= n; i++){
//			int nmc = mc;
//			for (int j = 0; j <= mc; j++){
//				if (dp[j][f][1] == INT_MAX)continue;
//				// do not buy
//				if (dp[j][!f][0] < dp[j][f][0]){
//					dp[j][!f][0] = dp[j][f][0];
//					dp[j][!f][1] = dp[j][f][1];
//				}
//				else if (dp[j][!f][0] == dp[j][f][0]){
//					if (dp[j][!f][1] > dp[j][f][1]){
//						dp[j][!f][1] = dp[j][f][1];
//					}
//				}
//
//				if (!(c[i] % 1000) && j < 500)continue; // do not buy !
//				// use change and get 500
//				int nc = (1000 - c[i] % 1000) + j - 500;
//				if (!(c[i] % 1000))nc = j - 500;
//				if (nc >= 0){ // get 500
//					if (dp[nc][!f][0] < dp[j][f][0] + 1){
//						dp[nc][!f][0] = dp[j][f][0] + 1;
//						dp[nc][!f][1] = dp[j][f][1] + c[i];
//					}
//					else if (dp[nc][!f][0] == dp[j][f][0] + 1){
//						if (dp[nc][!f][1] > dp[j][f][1] + c[i]){
//							dp[nc][!f][1] = dp[j][f][1] + c[i];
//						}
//					}
//				}
//
//				// do not use change
//				nc += 500;
//				if (nmc < nc)nmc = nc;
//				if (dp[nc][!f][0] < dp[j][f][0]){
//					dp[nc][!f][0] = dp[j][f][0];
//					dp[nc][!f][1] = dp[j][f][1] + c[i];
//				}
//				else if (dp[nc][!f][0] == dp[j][f][0]){
//					if (dp[nc][!f][1] > dp[j][f][1] + c[i]){
//						dp[nc][!f][1] = dp[j][f][1] + c[i];
//					}
//				}
//			}
//			f = !f;
//			mc = nmc;
//		}
//
//		int coin = -1, cost = INT_MAX;
//		for (int i = 0; i <= mc; i++){
//			for (int j = 0; j <= 1; j++){
//				if (coin < dp[i][j][0]){
//					coin = dp[i][j][0];
//					cost = dp[i][j][1];
//				}
//				else if (dp[i][j][0] == coin){
//					if (cost > dp[i][j][1]){
//						cost = dp[i][j][1];
//					}
//				}
//			}
//		}
//
//		printf("%d %d\n", coin, cost);
//	}
//}

#include <stdio.h>
#include <limits.h>

int c[103];
int dp[101003][2][2];

inline void update(int &ncoin, int &ncost, int coin, int cost){
	if (ncoin < coin){
		ncoin = coin;
		ncost = cost;
	}
	else if (ncoin == coin){
		if (ncost > cost){
			ncost = cost;
		}
	}
}

int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		for (int i = 1; i <= n; i++)scanf("%d", &c[i]);

		for (int i = 0; i <= n * 1000 + 1000; i++){
			dp[i][0][0] = dp[i][1][0] = 0;
			dp[i][0][1] = dp[i][1][1] = INT_MAX;
		}

		dp[0][0][1] = 0;
		int coin = -1, cost = INT_MAX;

		int mc = 0, f = 0; // max_change
		for (int i = 1; i <= n; i++){
			int nmc = mc;
			for (int j = 0; j <= mc; j++){
				if (dp[j][f][1] == INT_MAX)continue;

				update(coin, cost, dp[j][f][0], dp[j][f][1]);

				// do not buy
				update(dp[j][!f][0], dp[j][!f][1], dp[j][f][0], dp[j][f][1]);
				update(coin, cost, dp[j][!f][0], dp[j][!f][1]);

				if (!(c[i] % 1000) && j < 500)continue; // do not buy !
				// use change and get 500
				int nc = (1000 - c[i] % 1000) + j - 500;
				if (!(c[i] % 1000))nc = j - 500;

				if (nc >= 0){ // get 500
					update(dp[nc][!f][0], dp[nc][!f][1], dp[j][f][0] + 1, dp[j][f][1] + c[i]);
					update(coin, cost, dp[j][f][0] + 1, dp[j][f][1] + c[i]);
				}

				// do not use change
				nc += 500;
				if (nmc < nc)nmc = nc;

				update(dp[nc][!f][0], dp[nc][!f][1], dp[j][f][0], dp[j][f][1] + c[i]);
				update(coin, cost, dp[j][f][0], dp[j][f][1] + c[i]);
			}
			f = !f;
			mc = nmc;
		}

		printf("%d %d\n", coin, cost);
	}
}