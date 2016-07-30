#include <stdio.h>

long long CCW(int a, int b, int c, int d, int x, int y){
	long long k = a*d + c*y + x*b - c*b - x*d - a*y;
	if (k < 0)return -1;
	else if (k > 0)return 1;
	else
		return 0;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int lx, ly, lx2, ly2;
		scanf("%d %d %d %d", &lx, &ly, &lx2, &ly2);
		int x[5], y[5];
		scanf("%d %d %d %d", &x[0], &y[0], &x[2], &y[2]);
		x[1] = x[2], y[1] = y[0];
		x[3] = x[0], y[3] = y[2];
		x[4] = x[0], y[4] = y[0];

		bool flag = false;

		int lmy = ly < ly2 ? ly : ly2;
		int lMy = ly > ly2 ? ly : ly2;
		int lmx = lx < lx2 ? lx : lx2;
		int lMx = lx > lx2 ? lx : lx2;

		for (int i = 0; !flag && i <= 3; i++){

			int a = CCW(x[i], y[i], x[i+1], y[i+1], lx, ly) * CCW(x[i], y[i], x[i+1], y[i+1], lx2, ly2);
			int b = CCW(lx, ly, lx2, ly2, x[i], y[i]) * CCW(lx, ly, lx2, ly2, x[i+1], y[i+1]);

			if (a < 0 && b < 0)flag = true;
			else if (!a && !b){
				if (lx == x[i]){ // parallel to y axis
					int my = y[i] < y[i + 1] ? y[i] : y[i + 1];
					int My = y[i] > y[i + 1] ? y[i] : y[i + 1];
					if (My < lmy || lMy < my)continue;
					flag = true;
				}
				else{
					int mx = x[i] < x[i + 1] ? x[i] : x[i + 1];
					int Mx = x[i] > x[i + 1] ? x[i] : x[i + 1];
					if (Mx < lmx || lMx < mx)continue;
					flag = true;
				}
			}
		}

		printf("%c\n", flag ? 'T' : 'F');
	}
}

// 0 1 9 1 1 1 4 4
// 3 3 5 4 1 1 3 3