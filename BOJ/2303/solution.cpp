#include <stdio.h>
#include <algorithm>

using namespace std;

int e[6];

int main() {

	int n;
	scanf("%d", &n);

	int w = -1, y;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= 5; j++) {
			scanf("%d", &e[j]);
		}

		int x = 0;

		for (int j = 1; j <= 5; j++) {
			for (int k = j + 1; k <= 5; k++) {
				for (int l = k + 1; l <= 5; l++) {
					x = max(x, (e[j] + e[k] + e[l]) % 10);
				}
			}
		}

		if (w <= x) {
			w = x;
			y = i;
		}

	}

	printf("%d\n", y);

}