#include <stdio.h>
#include <limits.h>

#include <set>
#include <algorithm>

using namespace std;

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	set <int> v;

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		
		v.insert(a);
	}

	int ans = INT_MAX;

	for (auto &x : v) {
		
		set <int> ::iterator y = v.lower_bound(x + m);

		if (y == v.end())continue;

		ans = min(ans, *y - x);

	}

	printf("%d\n", ans);

}