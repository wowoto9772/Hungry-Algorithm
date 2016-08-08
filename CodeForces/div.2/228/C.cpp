#include <stdio.h>
#include <algorithm>

using namespace std;

int c[103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		int x;
		scanf("%d", &x);

		c[x]++;

	}

	int ans = 0, sum = 0;
	for (int i = 0; i <= 100; i++) {

		sum += c[i];

		ans = max(ans, sum / (i + 1) + (sum % (i + 1) ? 1 : 0));
	}

	printf("%d\n", ans);

}