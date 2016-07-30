#include <stdio.h>
#define ll long long

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int R;
		int tx, ty, tvx, tvy;
		int lx, ly, lvx, lvy;

		scanf("%d", &R);
		scanf("%d %d %d %d", &tx, &ty, &tvx, &tvy);
		scanf("%d %d %d %d", &lx, &ly, &lvx, &lvy);
		
		ll A = tx - lx;
		ll B = tvx - lvx;
		ll C = ty - ly;
		ll D = tvy - lvy;

		ll E = A*B + C*D;
		ll F = A*A + C*C - R*R;

		if (E >= 0){
			if (F <= 0)printf("Teemo died.\n");
			else
				printf("Teemo has to die.\n");
		}
		else{
			double G = -E*E / (double)(B*B + D*D);
			G += F;
			if (G <= 0)printf("Teemo died.\n");
			else
				printf("Teemo has to die.\n");
		}
	}
}