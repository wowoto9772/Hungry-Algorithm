#include <stdio.h>

char str[103][103];

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	int rr = 0, cc = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (j + 1 < c && str[i][j] == str[i][j + 1] && str[i][j] == '-') {
				for (int k = j; k < c; k++) {
					j = k;
					if (str[i][j] != '-') {
						j = k;
						break;
					}
				}
				rr++;
			}
			else if (str[i][j] == '-')rr++;
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (j + 1 < r && str[j][i] == str[j + 1][i] && str[j][i] == '|') {
				for (int k = j; k < r; k++) {
					j = k;
					if (str[j][i] != '|') {
						break;
					}
				}
				cc++;
			}
			else if (str[j][i] == '|')cc++;
		}
	}

	printf("%d\n", rr + cc);

}