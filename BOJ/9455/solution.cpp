#include <stdio.h>

int b[103][103];

int main() {
	
	int t;
	scanf("%d", &t);

	while (t--) {

		int r, c;
		scanf("%d %d", &r, &c);

		for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++)scanf("%d", &b[i][j]);

		int ans = 0;

		for (int i = 1; i <= c; i++) {

			int h = r;

			for (int j = r; j >= 1; j--) {
				if (b[j][i]) {
					ans += h - j;
					h--;
				}
			}
		}

		printf("%d\n", ans);

	}

}