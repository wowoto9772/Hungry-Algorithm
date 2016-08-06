#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int b[100003];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}

	int l = 1, r = 1000000000, m;

	int ans = INT_MAX;

	while (l <= r) {

		m = (l + r) / 2;

		int w = 0, c = 1;
		for (int i = 1; i <= n; i++) {
			if (w + b[i] <= m) {
				w += b[i];
			}
			else {
				if (m < b[i]) {
					c = k + 3;
					break;
				}
				else {
					w = b[i];
					c++;
				}
			}
		}

		if (c > k) {
			l = m + 1;
		}
		else{
			ans = min(ans, m);
			r = m - 1;
		}
	}


	printf("%d\n", ans);
}