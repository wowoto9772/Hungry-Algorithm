#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int cnt(int v) {

	if (!v)return 1;

	int r = 0;
	while (v) {
		r++;
		v /= 10;
	}

	return r;

}

bool cant[10];

bool conf(int v) {

	if (!v)return !cant[v];

	while (v) {
		int k = v % 10;
		if (cant[k])return false;
		v /= 10;
	}

	return true;
}

int main() {

	int n;
	scanf("%d", &n);

	int m;
	scanf("%d", &m);

	while (m--) {

		int k;
		scanf("%d", &k);
		cant[k] = true;

	}

	int ans = INT_MAX;

	for (int i = 0; i <= 1000000; i++) {

		if (i == 100) {
			ans = min(ans, abs(n - i));
		}
		else {

			if (conf(i)) {
				ans = min(ans, cnt(i) + abs(n - i));
			}

		}

	}

	printf("%d\n", ans);

}