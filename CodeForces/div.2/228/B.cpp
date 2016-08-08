#include <stdio.h>

int dr[] = { 0, 0, -1, 1, 0 };
int dc[] = { -1, 1, 0, 0, 0};

char str[103][103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%s", str[i]);

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			
			int c = str[i][j];
			if (c != '#')continue;

			int x = 0;

			for (int k = 0; k < 4; k++) {
				int ni = i + dr[k], nj = j + dc[k];
				if (str[i][j] == str[ni][nj])x++;
			}

			if (x == 4) {
				for (int k = 0; k < 5; k++) {
					int ni = i + dr[k], nj = j + dc[k];
					str[ni][nj] = '.';
				}
			}

		}
	}

	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)if (str[i][j] == '#') {
		printf("NO\n");
		return 0;
	}

	printf("YES\n");

}