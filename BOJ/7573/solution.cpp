#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int m, l, n;
	scanf("%d %d %d", &m, &l, &n);

	vector < pair<int, int> > v;

	vector < int > x, y;

	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		v.emplace_back(a, b);

		x.push_back(a);
		y.push_back(b);
	}

	sort(v.begin(), v.end());
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	x.resize(unique(x.begin(), x.end()) - x.begin());
	y.resize(unique(y.begin(), y.end()) - y.begin());

	int ans = 0;

	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			for (int w = 1; w < l / 2; w++) {
				int h = l / 2 - w;
				if (h < 0)break;
				int c = 0;
				for (int k = 0; k < v.size(); k++) {
					if (x[i] <= v[k].first && v[k].first <= x[i] + w) {
						if (y[j] <= v[k].second && v[k].second <= y[j] + h) {
							c++;
						}
					}
				}
				ans = max(ans, c);
			}
		}
	}

	printf("%d\n", ans);

}