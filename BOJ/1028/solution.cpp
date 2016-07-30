//#include <stdio.h>
//
//int I[753][753];
//int x[753][753];
//int y[753][753];
//
//int mm(int a, int b){ return a < b ? a : b; }
//
//int main(){
//	int R, C;
//	scanf("%d %d", &R, &C);
//
//	for (int i = 1; i <= R; i++){
//		for (int j = 1; j <= C; j++){
//			scanf("%1d", &I[i][j]);
//			x[i][j] = x[i - 1][j - 1] + I[i][j]; // left top to right bot diagonal
//			y[i][j] = y[i - 1][j + 1] + I[i][j]; // right top to left bot diagonal
//		}
//	}
//
//	int ans = 0;
//	for (int i = 1; i <= R; i++){
//		for (int j = 1; j <= C; j++){
//			if (I[i][j]){
//				int l = ans, r = mm(C - j, j - 1), m;
//				r = mm(r, (R - i) / 2);
//
//				int tmp = 0;
//				while (l <= r){
//					m = (l + r) / 2;
//					if (y[i + m][j - m] - y[i-1][j+1] == m+1 && x[i+m+m][j] - x[i+m-1][j-m-1] == m+1){
//						if (x[i + m][j + m] - x[i-1][j-1] == m+1 && y[i+m+m][j] - y[i+m-1][j+m+1] == m+1){
//							if (tmp < m + 1)tmp = m + 1;
//							l = m + 1;
//						}
//						else{
//							r = m - 1;
//						}
//					}
//					else{
//						r = m - 1;
//					}
//				}
//
//				if (ans < tmp)ans = tmp;
//			}
//		}
//	}
//
//	printf("%d\n", ans);
//}

#include <stdio.h>

int I[753][753];
int x[753][753];
int y[753][753];

int mm(int a, int b){ return a < b ? a : b; }

int main(){
	int R, C;
	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			scanf("%1d", &I[i][j]);
			x[i][j] = x[i - 1][j - 1] + I[i][j]; // left top to right bot diagonal
			y[i][j] = y[i - 1][j + 1] + I[i][j]; // right top to left bot diagonal
		}
	}

	int ans = 0;
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			if (I[i][j]){
				int l = ans, r = mm(C - j, j - 1), m;
				r = mm(r, (R - i) / 2);

				for (int k = l; k <= r; k++){
					m = k;
					if (y[i + m][j - m] - y[i - 1][j + 1] == m + 1 && x[i + m + m][j] - x[i + m - 1][j - m - 1] == m + 1){
						if (x[i + m][j + m] - x[i - 1][j - 1] == m + 1 && y[i + m + m][j] - y[i + m - 1][j + m + 1] == m + 1){
							if (ans < m + 1)ans = m + 1;
						}
					}
				}
			}
		}
	}

	printf("%d\n", ans);
}