#include <stdio.h>
#include <limits.h>

bool chk[103];
int e[103];
int l[103];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	int c = 0;
	int ans = 0;

	for (int i = 1; i <= k; i++)scanf("%d", &e[i]);

	for (int i = 1; i <= k; i++) {

		int x = e[i];

		if (!chk[x]) {

			if (c < n) {
				chk[x] = true;
				c++;
			}
			else {

				for (int y = 1; y <= k; y++) {
					if (chk[y]) {
						l[y] = k + 1;
						for (int j = i + 1; j <= k; j++) {
							if (y == e[j]) {
								l[y] = j;
								break;
							}
						}
					}
				}

				int z = 0, w;
				for (int y = 1; y <= k; y++) {
					if (chk[y]) {
						if (z < l[y]) {
							z = l[y];
							w = y;
						}
					}
				}

				chk[w] = false;
				chk[e[i]] = true;

				ans++;

			}

		}

	}

	printf("%d\n", ans);

}