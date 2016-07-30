#include <stdio.h>
#define ll long long

int s[] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

int main() {

	int m, n;

	while (scanf("%d %d", &m, &n) == 2) {

		bool flag = false;
		ll tot = 0;

		for (int i = 1;; i++) {

			ll l = s[i], r = s[i + 1] - 1;

			if (l <= m && m <= r && (ll)tot + (m - l + 1) * i < n)break;

			if (tot + (r - l + 1) * i >= n) {
				
				int stp = (n - tot) / i - 1;
				l += stp;
				tot += stp * i;

				while (tot + i < n) {
					l++;
					tot += i;
				}
				if (tot == n)printf("%d\n", l % 10);
				else {
					tot += i;
					while (tot > n) {
						l /= 10;
						tot--;
					}
					printf("%d\n", l % 10);
				}
				return 0;
			}
			else {
				tot += (r - l + 1) * i;
			}
		}

		if(!flag)printf("-1\n");

	}
}