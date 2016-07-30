#include <stdio.h>
#include <limits.h>

#include <algorithm>

using namespace std;

int a[200003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &a[i]);

	}

	sort(a, a + n);

	int ans = INT_MAX;
	int x, y;

	for (int i = 0; i < n - 1 && ans; i++) {
		int l = i + 1, r = n - 1, m;
		int val = -a[i];

		while (l <= r) {
			m = (l + r) / 2;
			if (a[m] < val)l = m + 1;
			else if (a[m] > val)r = m - 1;
			else
				break;
		}

		if (a[m] == val)ans = 0, x = i, y = m;
		else {
			if (ans > abs(a[m] + a[i])) {
				ans = abs(a[m] + a[i]);
				x = i, y = m;
			}
			if (m < n - 1 && ans > abs(a[m + 1] + a[i])) {
				ans = abs(a[m + 1] + a[i]);
				x = i, y = m + 1;
			}
			if (m - 1 > i && ans > abs(a[m - 1] + a[i])) {
				ans = abs(a[m - 1] + a[i]);
				x = i, y = m - 1;
			}
		}
	}

	printf("%d %d\n", a[x], a[y]);

} // 4 9 8 1 -5