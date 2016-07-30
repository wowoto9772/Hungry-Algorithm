#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int ans = 0;

	while (n--) {

		int h, m, d;
		scanf("%d:%d %d", &h, &m, &d);


		while (d--) {
			
			int x = h * 60 + m;

			if (60 * 7 <= x && x < 19 * 60)ans += 10;
			else
				ans += 5;

			m++;
			if (m >= 60) {
				m = 0;
				h++;
				if (h >= 24)h = 0;
			}
		}

	}

	printf("%d\n", ans);

}