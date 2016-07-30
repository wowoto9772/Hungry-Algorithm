#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	vector < pair<int, int> > v(n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &v[i].first);

		v[i].second = i;

	}

	sort(v.begin(), v.end());

	int ans = 0;

	for (int i = 0; i < v.size(); i++) {
		ans = max(v[i].second - i, ans);
	}

	printf("%d\n", ++ans);

}