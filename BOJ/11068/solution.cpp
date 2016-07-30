#include <stdio.h>

int d[23];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int v;
		scanf("%d", &v);

		int ans = 0;

		for (int i = 2; i <= 64 && !ans; i++) {

			int top = 0;

			int n = v;

			while (n) {
				d[top++] = n % i;
				n /= i;
			}

			bool flag = false;
			for (int j = 0; !flag && j < top / 2; j++) {
				if (d[j] != d[top - 1 - j])flag = true;
			}

			if (!flag) {
				ans = 1;
			}

		}

		printf("%d\n", ans);

	}

}