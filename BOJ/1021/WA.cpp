#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int s[53];
bool a[53];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &s[i]);
		a[s[i]] = true;
	}

	vector <int> p(n);

	for (int i = 0; i < n; i++)p[i] = i + 1;

	int ans = 0;

	for (int i = 0; i < m; i++) {

		int r = p.size();
		int l = 0;

		for (int j = 0; j < r; j++) {

			if (s[i] == p[j]) {

				int mii = min(l, r - j);
				ans += mii;

				if (l <= r - j) {
					for (int k = 0; k <= j; k++) {
						if (a[p[0]]) {
							if(k != j)p.push_back(p[0]);
						}
						p.erase(p.begin());
					}
				}
				else {
					for (int k = r - 1; k >= j; k--) {
						if (a[p.back()]) {
							if(k != j)p.insert(p.begin(), p.back());
						}
						p.pop_back();
					}
				}

				break;
			}
			else {
				l += a[p[j]];
			}
		}
	}

	printf("%d\n", ans);

}