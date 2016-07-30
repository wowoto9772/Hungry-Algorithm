#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int x, y, z, p, q, r;
		scanf("%d %d %d %d %d %d", &x, &y, &z, &p, &q, &r);

		bool f = false;
		int ans;

		for (int i = 1; i <= x*y*z + p + q + r; i++){
			if (i%x == p && i%y == q && i%z == r){
				ans = i;
				f = true;
				break;
			}
		}
		if (!f)ans = -1;

		printf("%d\n", ans);
	}
}