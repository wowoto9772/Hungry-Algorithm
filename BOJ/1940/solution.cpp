#include <stdio.h>
#include <limits.h>

#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	vector <int> v(n);

	for (int i = 0; i < n; i++)scanf("%d", &v[i]);

	v.push_back(INT_MAX);

	sort(v.begin(), v.end());

	int c = 0;

	for (int i = 0; i < n; i++) {
		int p = lower_bound(v.begin() + i + 1, v.end(), m - v[i]) - v.begin();
		if (v[p] == m - v[i]) {
			c++;
		}
	}

	printf("%d\n", c);

}