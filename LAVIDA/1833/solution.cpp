//#include <stdio.h>
//#include <memory.h>
//
//int tree[2003][2003];
//int dp[2003][2003];
//
//int n, m;
//
//int min(int a, int b){ return a < b ? a : b; }
//int max(int a, int b){ return a < b ? b : a; }
//
//int gcd(int a, int b){
//	int mod = 1;
//	while (mod){
//		mod = a % b;
//		a = b;
//		b = mod;
//	}return a;
//}
//
//void update(int x, int y, int val){
//	int y1;
//	while (x <= n){
//		y1 = y;
//		while (y1 <= m){
//			tree[x][y1] += val;
//			y1 += (y1 & -y1);
//		}
//		x += (x & -x);
//	}
//}
//
//int read(int x, int y){ // return sum from 1,1 to x,y.
//	int sum = 0;
//	while (x){
//		int y1 = y;
//		while (y1){
//			sum += tree[x][y1];
//			y1 -= y1 & -y1;
//		}
//		x -= x & -x;
//	}
//	return sum;
//}
//
//int main(){
//	int a, b;
//	while (scanf("%d %d %d %d", &n, &m, &a, &b) == 4 && n && m){
//
//		int g = gcd(a, b);
//		a /= g;
//		b /= g;
//		int sa = a, sb = b;
//
//		memset(tree, 0, sizeof(tree));
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= m; j++){
//				int a;
//				scanf("%1d", &a);
//				if (a)update(i, j, a);
//			}
//		}
//
//		memset(dp, 0, sizeof(dp));
//		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)dp[i][j] = read(i, j);
//
//		int ans = 0;
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= m; j++){
//				int l = 1, r = min((n - i + 1) / sa, (m - j + 1) / sb), md = 0;
//				int lst = 0;
//				while (l <= r){
//					md = (l + r) / 2;
//					int r1 = i, c1 = j;
//					int r2 = i + sa * md - 1, c2 = j + sb * md - 1;
//					// read(r1, c1, r2, c2) = read(r2, c2) - read(r2, c1 - 1) - read(r1 - 1, c2) + read(r1 - 1, c1 - 1);
//					int S = 0;
//					if (r1 <= r2 && c1 <= c2)S = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
//					if (!S){
//						l = md + 1;
//						lst = max(lst, md);
//					}
//					else{
//						r = md - 1;
//					}
//				}
//				ans += lst;
//				if (sa != sb){
//					l = 1, r = min((n - i + 1) / sb, (m - j + 1) / sa), md = 0;
//					lst = 0;
//					while (l <= r){
//						md = (l + r) / 2;
//						int r1 = i, c1 = j;
//						int r2 = i + sb * md - 1, c2 = j + sa * md - 1;
//						// read(r1, c1, r2, c2) 
//						int S = 0;
//						if (r1 <= r2 && c1 <= c2)S = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
//						if (!S){
//							l = md + 1;
//							lst = max(lst, md);
//						}
//						else{
//							r = md - 1;
//						}
//					}
//					ans += lst;
//				}
//			}
//		} // O(n^2 (lg(n))^2)
//
//		printf("%d\n", ans);
//	}
//}

#include <stdio.h>

int dp[2003][2003];

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a < b ? b : a; }

int gcd(int a, int b){
	int mod = 1;
	while (mod){
		mod = a % b;
		a = b;
		b = mod;
	}return a;
}

char str[2003];

int main(){
	int n, m, a, b;
	while (scanf("%d %d %d %d", &n, &m, &a, &b) == 4 && n && m){

		int g = gcd(a, b);
		a /= g;
		b /= g;

		for (int i = 1; i <= n; i++){
			scanf("%s", str+1);
			for (int j = 1; j <= m; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + str[j] - '0';
			}
		} // A | B = A + B - A & B


		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				int l = 1, r = min((n - i + 1) / a, (m - j + 1) / b), md = 0;
				int lst = 0;
				while (l <= r){
					md = (l + r) / 2;
					int r1 = i, c1 = j;
					int r2 = i + a * md - 1, c2 = j + b * md - 1;
					int S = 0;
					if (r1 <= r2 && c1 <= c2)S = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
					if (!S){
						l = md + 1;
						lst = max(lst, md);
					}
					else{
						r = md - 1;
					}
				}
				ans += lst;
				if (a != b){
					l = 1, r = min((n - i + 1) / b, (m - j + 1) / a), md = 0;
					lst = 0;
					while (l <= r){
						md = (l + r) / 2;
						int r1 = i, c1 = j;
						int r2 = i + b * md - 1, c2 = j + a * md - 1;
						int S = 0;
						if (r1 <= r2 && c1 <= c2)S = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
						if (!S){
							l = md + 1;
							lst = max(lst, md);
						}
						else{
							r = md - 1;
						}
					}
					ans += lst;
				}
			}
		} // O(n^2 lgn)

		printf("%d\n", ans);
	}
}