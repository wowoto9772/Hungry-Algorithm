#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		int w = 1 + i, h = 1 + (n - i);

		ans = max(ans, w*h);

	}

	printf("%d\n", ans);

}