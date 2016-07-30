#include <stdio.h>

int org[103];
int in[103];

bool occ[103];
int out[103];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &in[i]);
			org[i] = in[i];
			occ[i] = false;
		}

		int m = 0;

		for (int i = n; i >= 1; i--) {

			int mini = 103, p;

			for (int j = n; j >= 1; j--) {
				if (!occ[j]) {
					if (mini > in[j]) {
						mini = in[j];
						p = j;
					}
				}
			}

			out[p] = ++m;

			for (int j = p + 1; j <= n; j++) {
				if (in[j])in[j]--;
			}

			occ[p] = true;

		}

		bool flag = false;

		for (int i = n; !flag && i >= 1; i--) {

			for (int j = i - 1; j >= 1; j--) {
				if (out[j] < out[i])org[i]--;
			}

			if (org[i])flag = true;

		}

		if (flag)printf("IMPOSSIBLE");
		else {
			for (int j = 1; j <= n; j++)printf("%d ", out[j]);
		}

		printf("\n");

	}

}