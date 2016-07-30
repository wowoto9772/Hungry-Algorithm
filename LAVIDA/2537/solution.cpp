//#include <stdio.h>
//#include <memory.h>
//
//int dr[4] = {0, 1, 0, -1};
//int dc[4] = {1, 0, -1, 0}; 
//// go right, bot, left, top
//
//int main(){
//	int t;
//	scanf("%d", &t);
//	
//	while (t--){
//		int n, m, k;
//		scanf("%d %d %d", &n, &m, &k);
//
//		int chk[33][33];
//		memset(chk, 0x2f, sizeof(chk));
//		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)chk[i][j] = 0;
//
//		int r = 1, c = 1;
//		int flag = 0;
//
//		while (k--){
//			chk[r][c] = 1;
//			// first : fill outermost
//			// secont : next outermost
//			int nr = r + dr[flag];
//			int nc = c + dc[flag];
//			if (chk[nr][nc]){
//				flag++;
//				flag %= 4;
//				nr = r + dr[flag];
//				nc = c + dc[flag];
//			}
//			r = nr, c = nc;
//		}
//
//		int ans = 0;
//		for (int i = 0; i <= n+1; i++){
//			for (int j = 0; j <= m + 1; j++){
//				if (j <= m){
//					if (chk[i][j] == 0 && chk[i][j + 1] == 1)ans++;
//					if (chk[i][j] == 1 && chk[i][j + 1] == 0)ans++;
//				}
//				if (i <= n){
//					if (chk[i][j] == 0 && chk[i + 1][j] == 1)ans++;
//					if (chk[i][j] == 1 && chk[i + 1][j] == 1)ans++;
//				}
//			}
//		}
//
//		printf("%d\n", ans);
//	}
//}

//#include <stdio.h>
//#include <memory.h>
//
//int main(){
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n, m, k;
//		scanf("%d %d %d", &n, &m, &k);
//
//		if (n > m){
//			int a = n;
//			n = m;
//			m = a;
//		}
//
//		int chk[33][33];
//		memset(chk, 1, sizeof(chk));
//		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)chk[i][j] = 0;
//
//		int cur = 1;
//		while (k >= n){
//			for (int i = 1; i <= n; i++)chk[i][cur] = 1;
//			k -= n;
//			cur++;
//		}
//
//		if (k){
//			for (int i = n - 1; i >= 1 && k; i--){
//				if (i*i <= k && cur + i - 1 <= m){
//					for (int j = cur; j <= cur + i - 1; j++)for (int k = 1; k <= i; k++)chk[k][j] = 1;
//					cur += i;
//					k -= i*i;
//					i++;
//					continue;
//				}
//			}
//		}
//		while (k--){
//			bool flag = false;
//			for (int i = 1; !flag && i <= n; i++){
//				for (int j = 1; !flag && j <= m; j++){
//					if (chk[i][j] == 1 && chk[i][j + 1] == 0){
//						chk[i][j + 1] = 1;
//						flag = true;
//					}
//					if (chk[i][j] == 1 && chk[i + 1][j] == 0){
//						chk[i + 1][j] = 1;
//						flag = true;
//					}
//				}
//			}
//		}
//
//		int ans = 0;
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= m; j++){
//				if (chk[i][j] == 1 && chk[i + 1][j] == 0)ans++;
//				if (chk[i][j] == 1 && chk[i][j + 1] == 0)ans++;
//			}
//		}
//
//		printf("%d\n", ans);
//	}
//}

//#include <stdio.h>
//#include <memory.h>
//
//int main(){
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n, m, r;
//		scanf("%d %d %d", &n, &m, &r);
//
//		if (n > m){
//			int a = n;
//			n = m;
//			m = a;
//		}
//
//		int chk[33][33];
//		memset(chk, 0x2f, sizeof(chk));
//		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)chk[i][j] = 0;
//
//		if (r){
//			for (int i = n; i >= 1 && r; i--){
//				if (i*i <= r){
//					bool flag = false;
//					for (int j = 1; !flag && j <= m; j++){
//						for (int k = 1; !flag && k <= n; k++){
//							if (chk[j][k])continue;
//							else if(j+i-1 <= m && k+i-1 <= n && !chk[k+i-1][j+i-1]){
//								flag = true;
//								for (int a = j; a <= j + i - 1; a++){
//									for (int b = k; b <= k + i - 1; b++){
//										chk[b][a] = 1;
//									}
//								}
//							}
//						}
//					}
//					if (flag){
//						r -= i*i;
//						i++;
//						continue;
//					}
//				}
//			}
//		}
//		while (r--){
//			bool flag = false; // 많이 둘러 쌓인곳
//			int max = 0, wi, wj;
//			for (int i = 1; i <= n; i++){
//				for (int j = 1; j <= m; j++){
//					if (!chk[i][j]){
//						int c = 0;
//						if (chk[i][j - 1] == 1)c++;
//						if (chk[i][j + 1] == 1)c++;
//						if (chk[i - 1][j] == 1)c++;
//						if (chk[i + 1][j] == 1)c++;
//						if (max < c){
//							max = c;
//							wi = i;
//							wj = j;
//						}
//					}
//				}
//			}
//			chk[wi][wj] = 1;
//		}
//
//		int ans = 0;
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= m; j++){
//				if (chk[i][j] == 1 && chk[i + 1][j] == 0)ans++;
//				if (chk[i][j] == 1 && chk[i][j + 1] == 0)ans++;
//			}
//		}
//
//		printf("%d\n", ans);
//	}
//}

#include <stdio.h>
#include <limits.h>
#include <memory.h>

int min(int a, int b){ return a < b ? a : b; }

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m, r;
		scanf("%d %d %d", &n, &m, &r);

		if (r == 0)printf("0\n");
		else{

			if (n > m){
				int a = n;
				n = m;
				m = a;
			}

			if (r == n*m)printf("0\n");
			else{
				int ans = INT_MAX;
				int s = r / n;

				int rn = n;
				for (int i = s; i <= m && rn; i++){
					// rectangle & right
					int anx = r - r / rn * rn;
					if (anx){
						anx = 1;
					}
					if (rn < n)anx += r / rn;
					anx += rn;
					if (i + 1 == m){
						anx -= r % rn;
					}

					ans = min(ans, anx);
				}

				printf("%d\n", ans);
			}
		}
	}
} // 6 7 36 의 경우, 6 * 5 + 3 * 2 : 5

/*
30
6 6 5
4 6 16
9 5 0
29 3 87
28 22 145
30 30 156
15 16 157
27 28 157
5 5 6
7 6 36
7 6 6
30 30 895
10 10 90
1 1 1
30 30 870
30 30 24
30 30 36
30 30 884
5 9 5
4 4 16
28 29 666
30 30 841
30 30 31
6 6 25
5 5 2
5 5 23
6 10 56
20 25 437
5 2 4
2 2 4

*/

#include <stdio.h>

int main(){

}