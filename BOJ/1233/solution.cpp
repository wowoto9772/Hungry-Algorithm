#include <stdio.h>

int d[83];

int main() {

	int s[3];
	
	for (int i = 0; i < 3; i++)scanf("%d", &s[i]);

	for (int i = 1; i <= s[0]; i++) {
		for (int j = 1; j <= s[1]; j++) {
			for (int k = 1; k <= s[2]; k++) {
				d[i + j + k]++;
			}
		}
	}

	int maxi = 0, x;

	for (int i = 1; i <= s[0] + s[1] + s[2]; i++) {

		if (maxi < d[i]) {
			maxi = d[i];
			x = i;
		}

	}

	printf("%d\n", x);

}