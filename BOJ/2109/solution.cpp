#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

bool used[10003];

int main() {

	int n;
	scanf("%d", &n);

	int ans = 0;

	vector < pair<int, int> > v;

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		v.emplace_back(a, b);
	}

	sort(v.begin(), v.end());

	for (int i = n - 1; i >= 0; i--) {
		if (!used[v[i].second]) {
			ans += v[i].first;
			used[v[i].second] = true;
		}
		else {
			for (int j = v[i].second - 1; j >= 1; j--) {
				if (!used[j]) {
					ans += v[i].first;
					used[j] = true;
					break;
				}
			}
		}
	}

	printf("%d\n", ans);

}