#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	vector < pair <int, int> > my(n);

	while (n--) {
		scanf("%d %d", &my[n].first, &my[n].second);
		if (my[n].first > my[n].second) {
			int k = my[n].first;
			my[n].first = my[n].second;
			my[n].second = k;
		}
	}

	sort(my.begin(), my.end());

	int ans = 0;

	int le = -1000000001, ri = -1000000001;
	
	for (int i = 0; i < my.size(); i++) {
		if (ri < my[i].first) {
			ans += ri - le;
			le = my[i].first, ri = my[i].second;
		}else{
			ri = max(ri, my[i].second);
		}
	}

	ans += ri - le;

	printf("%d\n", ans);

}