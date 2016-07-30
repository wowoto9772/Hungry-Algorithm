#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int lis(const vector <int> &a) {
	vector <int> b;
	for (auto &n : a) {
		auto lo = lower_bound(b.begin(), b.end(), n);
		if (lo == b.end()) {
			b.push_back(n);
		}
		else {
			*lo = n;
		}
	}return b.size();
} // no duplicated 1 2 3 3 5 ==> 1 2 3 5

int main() {

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		int n, k;
		scanf("%d %d", &n, &k);

		vector <int> v(n);

		for (int i = 0; i < n; i++)scanf("%d", &v[i]);

		printf("Case #%d\n%d\n", ++tc, k <= lis(v));

	}

}