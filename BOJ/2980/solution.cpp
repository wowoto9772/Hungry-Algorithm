#include <stdio.h>

int r[1003], g[1003];

int main() {

	int n, l;
	scanf("%d %d", &n, &l);

	for (int i = 1; i <= n; i++) {
		int d;
		scanf("%d", &d);

		scanf("%d %d", &r[d], &g[d]);
	}

	int t, c = 0;
	for (t = 0; c < l; t++) {
		if (!r[c])c++;
		else {
			int k = t % (r[c] + g[c]);
			if (k >= r[c])c++;
		}
	}

	printf("%d\n", t);

}