//#include <stdio.h>
//#include <limits.h>
//#include <memory.h>
//
//#include <vector>
//
//#define MAX 1000000007
//
//using namespace std;
//
//class ele{
//public:
//	int a, c;
//};
//
//int m(int a, int b){ return a < b ? a : b; }
//int dp[10002][202][2];
//
//int main(){
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int M, N, L, G;
//		scanf("%d %d %d %d", &M, &N, &L, &G);
//
//		ele lpsh, lpop;
//
//		vector <ele> lnk[10003];
//		for (int i = 1; i <= M; i++){ // 4
//			for (int j = 1; j < N; j++){ // 6
//				int cst;
//				scanf("%d", &cst);
//
//				int cur = (i - 1) * N + j;
//				int nxt = cur + 1;
//
//				lpsh.a = nxt, lpsh.c = cst;
//				lnk[cur].push_back(lpsh);
//			}
//		}
//
//		for (int i = 1; i < M; i++){ // 4
//			for (int j = 1; j <= N; j++){ // 6
//				int cst;
//				scanf("%d", &cst);
//
//				int cur = (i - 1) * N + j;
//				int nxt = cur + N;
//
//				lpsh.a = nxt, lpsh.c = cst;
//				lnk[cur].push_back(lpsh);
//			}
//		}
//
//		for (int i = 1; i <= N*M; i++)for (int j = 0; j < M + N; j++)dp[i][j][0] = dp[i][j][1] = MAX;
//
//		dp[1][0][0] = dp[1][0][1] = 0; // node, cnt, tog
//		int ans = INT_MAX;
//
//		for (int i = 0; i < M + N; i++){
//			for (int j = 1; j <= M*N; j++){
//				int c = j;
//				for (int k = 0; k < lnk[j].size(); k++){
//					lpsh = lnk[j][k];
//					int n = lpsh.a;
//					for (int t = 0; t <= 1; t++){ // toggle
//						if (dp[j][i][t] >= MAX)continue;
//						else{
//							// k == 1 toggle
//							//int pt = L;
//
//							int tog = 0;
//							if (n - c == 1){ // wide
//								if (!t){
//									//pt++;
//									tog = 1;
//								}
//							}
//							else{
//								if (t){
//									//pt++;
//									tog = 1;
//								}
//							}
//
//							int nxtc = dp[j][i][t] + lnk[c][k].c;
//							if (nxtc <= G){
//								dp[n][i + tog][t ^ tog] = m(dp[n][i + tog][t ^ tog], nxtc);
//								if (n == N*M){
//									ans = m(ans, L * (M + N - 2) + (i + tog));
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//
//		printf("%d\n", ans == INT_MAX ? -1 : ans);
//	}
//}

#include <stdio.h>
#include <limits.h>
#include <memory.h>

#include <vector>

#define MAX 1000000007

using namespace std;

class ele{
public:
	int a, c;
};

int m(int a, int b){ return a < b ? a : b; }
int dp[10002][202][2];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int M, N, L, G;
		scanf("%d %d %d %d", &M, &N, &L, &G);

		ele lpsh, lpop;

		vector <ele> lnk[10003];
		for (int i = 1; i <= M; i++){ // 4
			for (int j = 1; j < N; j++){ // 6
				int cst;
				scanf("%d", &cst);

				int cur = (i - 1) * N + j;
				int nxt = cur + 1;

				lpsh.a = nxt, lpsh.c = cst;
				lnk[cur].push_back(lpsh);
			}
		}

		for (int i = 1; i < M; i++){ // 4
			for (int j = 1; j <= N; j++){ // 6
				int cst;
				scanf("%d", &cst);

				int cur = (i - 1) * N + j;
				int nxt = cur + N;

				lpsh.a = nxt, lpsh.c = cst;
				lnk[cur].push_back(lpsh);
			}
		}

		for (int i = 1; i <= N*M; i++)for (int j = 0; j < M + N; j++)dp[i][j][0] = dp[i][j][1] = MAX;

		dp[1][0][0] = dp[1][0][1] = 0; // node, cnt, tog
		int ans = INT_MAX;

		for (int i = 0; i < M + N; i++){
			for (int j = 1; j <= M*N; j++){
				int c = j;
				for (int k = 0; k < lnk[j].size(); k++){
					lpsh = lnk[j][k];
					int n = lpsh.a;
					for (int t = 0; t <= 1; t++){ // toggle
						if (dp[j][i][t] >= MAX)continue;
						else{
							// k == 1 toggle
							int tog = 0;
							if (n - c == 1){ // wide
								if (!t){
									tog = 1;
								}
							}
							else{
								if (t){
									tog = 1;
								}
							}

							int nxtc = dp[j][i][t] + lnk[c][k].c;
							if (nxtc <= G){
								dp[n][i + tog][t ^ tog] = m(dp[n][i + tog][t ^ tog], nxtc);
								if (n == N*M){
									ans = m(ans, L * (M + N - 2) + (i + tog));
								}
							}
						}
					}
				}
			}
		}

		printf("%d\n", ans == INT_MAX ? -1 : ans);
	}
}