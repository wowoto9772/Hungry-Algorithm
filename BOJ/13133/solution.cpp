#include <stdio.h>

int m[503], f[503];

bool d[503];


int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		int a, b;
		scanf("%d %d", &a, &b);

		m[i] = a;
		f[i] = b;

	}

	d[0] = true;

	int x;
	scanf("%d", &x);

	while (x--) {

		int k;
		scanf("%d", &k);

		d[k] = true;

	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!d[m[i]] && !d[f[i]] && !d[i]) {
			ans++;
		}
	}

	printf("%d\n", ans);

}