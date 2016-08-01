#include <stdio.h>

int p[4];

int c[103];

int main() {

	for (int i = 1; i <= 3; i++)scanf("%d", &p[i]);

	int n = 3;
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);

		for (int i = a; i < b; i++)c[i]++;
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++)ans += p[c[i]] * c[i];

	printf("%d\n", ans);

}