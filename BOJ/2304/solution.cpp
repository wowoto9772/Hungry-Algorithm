#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define p first
#define h second

int main() {

	int n;
	scanf("%d", &n);

	vector < pair <int, int> > v(n);

	for (int i = 0; i < n; i++) {
		
		scanf("%d %d", &v[i].p, &v[i].h);

	}

	v.emplace_back(0, 0);

	sort(v.begin(), v.end());

	int ans = 0;

	int maxii = 0;

	for (int i = 0; i < n;) {
		
		int maxi = v[i].second, x;
		
		for (int j = i + 1; j <= n; j++) {
			if (maxi < v[j].h) {
				maxi = v[j].h;
				maxii = maxi;
				x = j;
				break;
			}
		}

		if (maxi > v[i].second) {

			ans += (v[x].p - v[i].p) * v[i].h;

		}
		else {

			maxi = 0;

			for (int j = i + 1; j <= n; j++) {
				if (maxi < v[j].h) {
					maxi = v[j].h;
					x = j;
				}
			}

			ans += (v[x].p - v[i].p) * v[x].h;

		}

		i = x;

	}

	printf("%d\n", ans + maxii);

}