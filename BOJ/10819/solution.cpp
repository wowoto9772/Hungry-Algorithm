#include <stdio.h>
#include <algorithm>

using namespace std;

int a[10];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	sort(a, a + n);

	int ans = 0;

	while (true) {
		int tmp = 0;
		for (int i = 0; i < n - 1; i++) {
			tmp += abs(a[i] - a[i + 1]);
		}
		ans = max(ans, tmp);
		if (!next_permutation(a, a + n))break;
	}

	printf("%d\n", ans);

}