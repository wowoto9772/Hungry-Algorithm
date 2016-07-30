#include <stdio.h>

int A[53], B[53], C[53];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		bool chk[99999] = {};

		int a, b, c;

		scanf("%d", &a);
		for (int i = 0; i < a; i++)scanf("%d", &A[i]);

		scanf("%d", &b);
		for (int i = 0; i < b; i++)scanf("%d", &B[i]);

		scanf("%d", &c);
		for (int i = 0; i < c; i++)scanf("%d", &C[i]);

		int ans = 0;

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int k = 0; k < c; k++) {

					int x = A[i] + B[j] + C[k];

					if (chk[x])continue;

					chk[x] = true;

					bool flag = false;

					while (x) {
						int y = x % 10;
						if (y == 5 || y == 8) {
							x /= 10;
							continue;
						}
						flag = true;
						break;
					}

					if (!flag)ans++;
				}
			}
		}

		printf("%d\n", ans);
	}

}