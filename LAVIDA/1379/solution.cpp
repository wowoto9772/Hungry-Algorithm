//#include <stdio.h>
//
//int M(int a, int b){ return a < b ? b : a; }
//int m(int a, int b){ return a < b ? a : b; }
//
//void swp(int *a, int *b){
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//
//int x[4], y[4];
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		for (int i = 0; i < 4; i++)scanf("%d %d", &x[i], &y[i]);
//		if (x[0] > x[1])swp(&x[0], &x[1]);
//		if (y[0] > y[1])swp(&y[0], &y[1]);
//		if (x[2] > x[3])swp(&x[2], &x[3]);
//		if (y[2] > y[3])swp(&y[2], &y[3]);
//		if (x[0] > x[2]){
//			swp(&x[0], &x[2]);
//			swp(&y[0], &y[2]);
//			swp(&x[1], &x[3]);
//			swp(&y[1], &y[3]);
//		}
//
//		int ans = 0;
//
//		if (x[0] <= x[2] && x[2] <= x[1]){
//			if (y[0] <= y[2] && y[2] <= y[1]){
//				int y_ = m(y[1], y[3]), x_ = m(x[1], x[3]);
//				int y__ = M(y[0], y[2]), x__ = M(x[0], x[2]);
//				if (y__ <= y_ && x__ <= x_){
//					ans = (y_ - y__) * (x_ - x__);
//				}
//			}
//		}
//
//		printf("%d\n", ans);
//	}
//}

#include <stdio.h>

int M(int a, int b){ return a < b ? b : a; }
int m(int a, int b){ return a < b ? a : b; }

void swp(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int x[4], y[4];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		for (int i = 0; i < 4; i++)scanf("%d %d", &x[i], &y[i]);
		
		if (x[0] > x[1])swp(&x[0], &x[1]);
		if (y[0] > y[1])swp(&y[0], &y[1]);
		if (x[2] > x[3])swp(&x[2], &x[3]);
		if (y[2] > y[3])swp(&y[2], &y[3]);

		int ans = 0;

		int y_ = m(y[1], y[3]), x_ = m(x[1], x[3]);
		int y__ = M(y[0], y[2]), x__ = M(x[0], x[2]);
		if (y__ <= y_ && x__ <= x_){
			ans = (y_ - y__) * (x_ - x__);
		}

		printf("%d\n", ans);
	}
}