#include <stdio.h>

int a[103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	int ans = 0;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] >= a[i + 1]) {
			ans += a[i] - (a[i + 1] - 1);
			a[i] = a[i + 1] - 1;
		}
	}

	printf("%d\n", ans);

}