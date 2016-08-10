#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	int ans = -1003;

	int c = 0;

	for (int i = 1; i <= n; i++) {

		int v;
		scanf("%d", &v);

		c += v;

		ans = max(ans, c);

		if (c < 0)c = 0;

	}

	printf("%d\n", ans);

}