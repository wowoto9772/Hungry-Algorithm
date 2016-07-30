#include <stdio.h>

bool chk[23][23][5];

int dr[] = { 0, 1, 1, -1 };
int dc[] = { 1, 0, 1, 1 };

int o[23][23];

int main() {

	int n = 19;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &o[i][j]);
		}
	}

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (o[i][j]) {
				for (int k = 0; k < 4; k++) {

					if (chk[i][j][k])continue;

					int flg = 1;
					int ni = i, nj = j;

					chk[i][j][k] = true;

					while (true) {

						ni += dr[k];
						nj += dc[k];

						if (ni < 1 || nj < 1 || ni > n || nj > n) {
							break;
						}

						if (o[i][j] == o[ni][nj]) {

							if (chk[ni][nj][k])break;
							chk[ni][nj][k] = true;

							flg++;
						}
						else
							break;
					}

					if (flg == 5) {
						printf("%d\n", o[i][j]);
						printf("%d %d\n", i, j);
						return 0;
					}
				}
			}
		}
	}


	printf("0\n");

}

/*
	1 1 1 1 1 1
	0 1 1 1 1 1
	0 0 1 1 1 1
	0 0 0 1 1 1
	0 0 0 0 1 1
	0 0 0 0 0 1
*/