#include <stdio.h>
#include <algorithm>

using namespace std;

int c[8];

int main() {

	int n = 6;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}

	int ans = c[6];

	if (c[5]) {

		ans += c[5];

		c[1] -= c[5] * 11;

		if (c[1] < 0)c[1] = 0;

	}


	if (c[4]) {

		ans += c[4];

		c[2] -= c[4] * 5;

		if (c[2] < 0)c[2] = 0;

	}



	if (c[3]) {

		ans += c[3] / 4;

		c[3] %= 4;

		if (c[3]) {

			ans++;

			if (c[3] == 1) {

				int mini = min(c[2], 5);

				c[2] -= mini;

				int sum = 36 - 9 - mini * 4;

				mini = min(sum, c[1]);

				c[1] -= mini;

			}
			else if (c[3] == 2) {

				int mini = min(c[2], 3);

				c[2] -= mini;

				int sum = 36 - 9 * 2 - mini * 4;

				mini = min(sum, c[1]);

				c[1] -= mini;

			}
			else {

				int mini = min(c[2], 1);

				c[2] -= mini;

				int sum = 36 - 9 * 3 - mini * 4;

				mini = min(sum, c[1]);

				c[1] -= mini;

			}

		}

	}

	if (c[2]) {

		ans += c[2] / 9;

		c[2] %= 9;

		if (c[2]) {

			ans++;

			int mini = min(36 - c[2] * 4, c[1]);

			c[1] -= mini;

		}

	}

	if (c[1]) {

		ans += c[1] / 36;

		c[1] %= 36;

		if (c[1])ans++;

	}

	printf("%d\n", ans);

}