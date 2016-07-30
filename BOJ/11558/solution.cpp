#include <stdio.h>

int nxt[10003];
bool cyc[10003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &nxt[i]);
			cyc[i] = false;
		}

		int k = 0;
		int f = 1;

		while (!cyc[f]) {

			cyc[f] = true;
			if (cyc[n])break;

			f = nxt[f];
			k++;
		}

		if (!cyc[n])k = 0;

		printf("%d\n", k);

	}

}