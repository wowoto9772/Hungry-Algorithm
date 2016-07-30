#include <stdio.h>

bool p[1003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 2; i <= n; i++) {
		if (!p[i]) {
			k--;
			if (k == 0) {
				printf("%d\n", i);
				return 0;
			}
			for (int j = i*i; j <= n; j += i) {
				if (!p[j]) {
					p[j] = true;
					k--;
					if (k == 0) {
						printf("%d\n", j);
						return 0;
					}
				}
			}
		}
	}

}