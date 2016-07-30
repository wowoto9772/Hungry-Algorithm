#include <stdio.h>

char I[2][33][33]; // 0, 1

int main()
{
	int t;
	scanf("%d", &t);

	while (t--) {

		int W, H, n;
		scanf("%d %d %d", &W, &H, &n);

		int R[2] = { 0 };

		for (int i = H - 1; i >= 0; i--) {
			scanf("%s", I[0][i]);
			for (int j = 0; j < W; j++) {
				if (I[0][i][j] == '#')R[0]++;
			}
		}

		for (int i = H - 1; i >= 0; i--) {
			scanf("%s", I[1][i]);
			for (int j = 0; j < W; j++) {
				if (I[1][i][j] == '#')R[1]++;
			}
		}

		while (n > 0 && R[0] && R[1]) {

			for (int i = 0; i < 2; i++) {

				int a, b;

				while (n-- > 0) {

					scanf("%d %d", &b, &a);

					if (I[i ^ 1][a][b] == '#') {
						R[i ^ 1]--;
						I[i ^ 1][a][b] = '_';
						if (!R[i ^ 1])break;
					}
					else {
						break;
					}
				}
			}

			if (!R[0] || !R[1])break;

		}


		while (n-- > 0) {
			scanf("%*d %*d");
		}

		if ((R[0] && R[1]) || (!R[0] && !R[1]))printf("draw\n");
		else if (R[0])printf("player one wins\n");
		else
			printf("player two wins\n");
	}
}