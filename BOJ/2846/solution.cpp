#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	int ans = 0;

	int c;
	scanf("%d", &c);

	int p = c;
	for (int i = 2; i <= n; i++) {
		int a;
		scanf("%d", &a);

		if (p >= a) {
			ans = max(ans, p - c);
			c = a;
		}

		p = a;
	}

	ans = max(ans, p - c);

	printf("%d\n", ans);

}