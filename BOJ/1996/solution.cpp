#include <stdio.h>

char str[1003][1003];
int ans[1003][1003];

int dr[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dc[] = { 0, -1, 1, -1, 1, 0, -1, 1 };

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%s", str[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (str[i][j] >= '1' && str[i][j] <= '9') {
				for (int k = 0; k < 8; k++) {
					int ni = i + dr[k], nj = j + dc[k];
					if (ni < 0 || nj < 0 || ni >= n || nj >= n)continue;
					ans[ni][nj] += str[i][j] - '0';
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (str[i][j] >= '1' && str[i][j] <= '9') {
				printf("*");
			}
			else {
				if (ans[i][j] >= 10)printf("M");
				else
					printf("%d", ans[i][j]);
			}
		}printf("\n");
	}

}