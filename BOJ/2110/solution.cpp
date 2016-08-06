#include <stdio.h>
#include <algorithm>

using namespace std;

int p[200003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}

	sort(p + 1, p + 1 + n);

	int l = 0, r = 1000000000, m;

	int ans = 0;

	while (l <= r) {

		m = (l + r) / 2;

		int c = 1, lst = p[1];

		for (int i = 2; i <= n; i++) {
			if (p[i] - lst >= m) {
				lst = p[i];
				c++;

				if (c > k)break;
			}
		}

		if (c >= k) {
			ans = max(ans, m);
			l = m + 1;
		}
		else {
			r = m - 1;
		}

	}

	printf("%d\n", ans);

}