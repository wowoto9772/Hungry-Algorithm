#include <stdio.h>

int main() {

	int tc = 0;

	int n;
	while (scanf("%d", &n) == 1 && n) {

		int a[103][103];
		for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)scanf("%d", &a[i][j]);

		int ans = -4000003;

		for (int d = 0; d < 4; d++) {

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					int s = 0;
					if (j <= n - 3) { // ¤Ñ
						s = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
						if (ans < s)ans = s;
					}
					if (i < n) { // ¤±
						if (j < n) {
							s = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
							if (ans < s)ans = s;
						}
						if (j <= n - 2) {
							s = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2]; // ¤©
							if (ans < s)ans = s;
							s = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2]; // ¤¡
							if (ans < s)ans = s;
							s = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1]; // ¤Ì
							if (ans < s)ans = s;
						}
					}
				}
			}

			int nd = n / 2;
			int b[103][103];

			for (int i = 1; i <= n; i++) { // 90 degree
				for (int j = 1; j <= n; j++) {
					b[j][n + 1 - i] = a[i][j];
				}
			}

			for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)a[i][j] = b[i][j];

		}

		printf("%d. %d\n", ++tc, ans);

	}

}