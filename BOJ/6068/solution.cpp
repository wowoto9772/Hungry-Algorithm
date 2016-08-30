#include <stdio.h>
#include <vector>

#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	vector < pair<int, int> > must;

	for (int i = 0; i < n; i++) {

		int a, b;
		scanf("%d %d", &a, &b);

		must.emplace_back(b, a);

	}

	sort(must.begin(), must.end());

	int l = 0, r = 1000000, m;

	int ans = -1;

	while (l <= r) {

		m = (l + r) / 2;

		int c = m;
		bool pos = true;

		for (int i = 0; pos && i < must.size(); i++) {

			if (c + must[i].second <= must[i].first) {
				c += must[i].second;
			}
			else {
				pos = false;
			}

		}

		if (pos) {
			ans = max(ans, m);
			l = m + 1;
		}
		else {
			r = m - 1;
		}

	}

	printf("%d\n", ans);

}
