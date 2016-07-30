#include <stdio.h>
#include <algorithm>

using namespace std;

int jew[300003];

int main() {

	int n, c;
	scanf("%d %d", &n, &c);

	for (int i = 0; i < c; i++)scanf("%d", &jew[i]);

	int l = 1, r = 1000000000, m;

	int ans = r;

	while (l <= r) {
		
		m = (l + r) / 2;

		int cmp = 0;

		for (int i = 0; i < c; i++) {
			cmp += jew[i] / m;
			cmp += (jew[i] % m) ? 1 : 0;
			if (cmp > n)break;
		}

		if (cmp > n) {
			l = m + 1;
		}
		else {
			ans = min(ans, m);
			r = m - 1;
		}

	}

	printf("%d\n", ans);

}