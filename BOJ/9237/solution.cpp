#include <stdio.h>
#include <algorithm>

using namespace std;

int t[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d", &t[i]);

	sort(t, t + n);

	int ans = 0;
	int m = 1;

	for (int i = n - 1; i >= 0; i--) {
		ans = max(ans, m + 1 + t[i]);
		m++;
	}

	printf("%d\n", ans);

}