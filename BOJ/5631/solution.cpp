#include <stdio.h>
#include <math.h>

class ele{
public:
	int x, y;
}I[200003];

int main()
{
	int n, t = 1;
	while (scanf("%d", &n) == 1 && n){
		for (int i = 1; i <= n; i++)scanf("%d %d", &I[i].x, &I[i].y);
		int x[2], y[2];
		for (int i = 0; i < 2; i++)scanf("%d %d", &x[i], &y[i]);
		int q;
		scanf("%d", &q);

		int R1[13002] = { 0 }, R2[13002] = { 0 };
		for (int i = 0; i <= n; i++){
			int X = (x[0] - I[i].x)*(x[0] - I[i].x) + (y[0] - I[i].y)*(y[0] - I[i].y);
			int Y = (x[1] - I[i].x)*(x[1] - I[i].x) + (y[1] - I[i].y)*(y[1] - I[i].y);
			int X_ = sqrt((double)X);
			int Y_ = sqrt((double)Y);
			if (X_ <= 13000){
				if (X_*X_ == X){
					R1[X_]++;
				}
				else{
					if (X_ <= 13000){
						R1[X_ + 1]++;
					}
				}
			}
			if (Y_ <= 13000){
				if (Y_*Y_ == Y){
					R2[Y_]++;
				}
				else{
					if (Y_ <= 13000){
						R2[Y_ + 1]++;
					}
				}
			}
		}

		for (int i = 1; i <= 13000; i++){
			R1[i] += R1[i - 1];
			R2[i] += R2[i - 1];
		}

		int ans[20003];

		for (int i = 1; i <= q; i++){
			int r1, r2;
			scanf("%d %d", &r1, &r2);

			ans[i] = n - R1[r1] - R2[r2];
			if (ans[i] < 0)ans[i] = 0;
			// (AUB)^c - (A^B)
			// = U - (AUB) - (A^B)
			// = U - (A + B)
		}

		printf("Case %d:\n", t++);
		for (int i = 1; i <= q; i++)printf("%d\n", ans[i]);
	}
}