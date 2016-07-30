#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[13][13];
char out[13][13];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	int mr = 11, Mr = -1, mc = 11, Mc = -1;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int s = 0;
			out[i][j] = str[i][j];
			for (int k = 0; k < 4; k++) {
				int ni = i + dr[k], nj = j + dc[k];
				if (ni < 0 || ni >= r || nj < 0 || nj >= c || str[ni][nj] == '.')s++;
			}
			if (s >= 3)out[i][j] = '.';
			if (out[i][j] == 'X') {
				mr = min(mr, i);
				Mr = max(Mr, i);
				mc = min(mc, j);
				Mc = max(Mc, j);
			}
		}
	}

	for (int i = mr; i <= Mr; i++) {
		for (int j = mc; j <= Mc; j++)printf("%c", out[i][j]);
		printf("\n");
	}

}