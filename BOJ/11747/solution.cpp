#include <stdio.h>

int v[1003];
bool chk[10003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	for (int k = 0; k < 4; k++) {

		for (int j = 1; j + k <= n; j++) {

			int x = 0;

			for (int l = j; l <= j + k; l++) {
				x = x * 10 + v[l];
			}
			
			chk[x] = true;

		}

	}

	for (int i = 0;; i++) {
		if (!chk[i]) {
			printf("%d\n", i);
			return 0;
		}
	}

}