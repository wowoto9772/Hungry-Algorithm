#include <stdio.h>
#include <string.h>

char org[10003];
char str[103][103];
char _90[103][103];

int par[10003];

int main() {

	for (int i = 1; i <= 100; i++) {
		par[i*i] = i;
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s", org);

		int s = strlen(org);

		int n = par[s];

		int r = 0;
		int c = 0;

		for (int i = 0; i < s; i++) {

			str[r][c++] = org[i];

			if (c == n) {
				c = 0, r++;
			}

		}

		for (int c = 1; c <= 3; c++) { // 90 =>

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					_90[j][n - 1 - i] = str[i][j];
				}
			}

			for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)str[i][j] = _90[i][j];

		}

		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)printf("%c", _90[i][j]);

		printf("\n");

	}

}