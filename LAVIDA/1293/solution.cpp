#include <stdio.h>
#define ll long long

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int R;
		int a, b, c, da, db, dc;
		int x, y, z, dx, dy, dz;

		scanf("%d", &R);
		scanf("%d %d %d %d %d %d", &a, &b, &c, &da, &db, &dc);
		scanf("%d %d %d %d", &x, &y, &z, &dx, &dy, &dz);

		ll A = a - x;
		ll B = da - dx;
		ll C = b - y;
		ll D = db - dy;
		ll E = c - z;
		ll F = dc - dz;

		ll L = A*B + C*D + E*F;
		ll M = A*A + C*C + E*E - R*R;

		if (L >= 0){
			if (M <= 0)printf("YES\n");
			else
				printf("NO\n");
		}
		else{
			double N = -L*L / (double)(B*B + D*D + F*F);
			N += M;
			if (N <= 0)printf("YES\n");
			else
				printf("NO\n");
		}
	}
}