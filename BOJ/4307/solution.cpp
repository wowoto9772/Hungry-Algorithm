#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int l, n;
		scanf("%d %d", &l, &n);

		int m = 0, M = 0;

		for (int i = 1; i <= n; i++) {

			int x;
			scanf("%d", &x);

			m = max(min(x, l - x), m);
			M = max(max(x, l - x), M);

		}

		printf("%d %d\n", m, M);

	}

}