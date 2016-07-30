#include <stdio.h>

char str[103][103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%s", str[i]);

	int rr = 0, cc = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (str[i][j] == str[i][j + 1] && str[i][j] == '.') {
				for (int k = j; k < n; k++) {
					j = k;
					if (str[i][j] != '.') {
						j = k;
						break;
					}
				}
				rr++;
			}
		}
		for (int j = 0; j < n - 1; j++) {
			if (str[j][i] == str[j + 1][i] && str[j][i] == '.') {
				for (int k = j; k < n; k++) {
					j = k;
					if (str[j][i] != '.') {
						break;
					}
				}
				cc++;
			}
		}
	}

	printf("%d %d\n", rr, cc);

}

/*
5
..*..
..*..
..*..
..*..
..*..
*/