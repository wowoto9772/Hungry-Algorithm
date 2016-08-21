#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int nim = 0;

	int one = 0;

	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);

		nim ^= x;

		one += x == 1;
	}

	// misere play

	int winner = 0;

	if (one == n) {
		if (nim) {
			// second win
			winner = 2;
		}
		else {
			winner = 1;
		}
	}
	else {
		if (nim) {
			// first win
			winner = 1;
		}
		else {
			winner = 2;
		}
	}

	if (winner == 1) {
		printf("koosaga");
	}
	else {
		printf("cubelover");
	}

}