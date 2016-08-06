#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int s[53];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &s[i]);
	}

	vector <int> p(n);

	for (int i = 0; i < n; i++)p[i] = i + 1;

	int ans = 0;

	for (int i = 0; i < m; i++) {

		int r = p.size();

		for (int j = 0; j < r; j++) {

			if (s[i] == p[j]) {

				int mii = min(j, r - j);
				ans += mii;

				if (j <= r - j) {
					for (int k = 0; k <= j; k++) {
						if (k != j)p.push_back(p[0]);
						p.erase(p.begin());
					}
				}
				else {
					for (int k = r - 1; k >= j; k--) {
						if (k != j)p.insert(p.begin(), p.back());
						p.pop_back();
					}
				}

				break;
			}
		}
	}

	printf("%d\n", ans);

}