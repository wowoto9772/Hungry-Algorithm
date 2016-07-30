#include <stdio.h>

#include <algorithm>

using namespace std;

#define ll long long

ll e[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%lld", &e[i]);

	sort(e, e + n);

	ll pts = 0;

	int l = 0, r = n - 1;

	while (l <= r) {

		if (l < r) {
			if (e[r - 1] > 1) {
				pts += e[r] * e[r - 1];
				r -= 2;
			}
			else if (e[l] * e[l + 1] >= 0 && e[l] < 0) {
				pts += e[l] * e[l + 1];
				l += 2;
			}
			else {
				pts += e[l];
				l++;
			}
		}
		else {
			pts += e[l];
			l++;
		}

	}

	printf("%lld\n", pts);

}