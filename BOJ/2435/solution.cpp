#include <stdio.h>
#include <algorithm>

using namespace std;

int x[103];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)scanf("%d", &x[i]);

	int tmp = 0;
	int ans = -203;
	for (int i = 1; i <= n; i++) {
		tmp += x[i];
		if (i > k)tmp -= x[i - k];
		if (i >= k) {
			ans = max(ans, tmp);
		}
	}


	printf("%d\n", ans);

}