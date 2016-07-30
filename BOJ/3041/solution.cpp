#include <stdio.h>
#include <algorithm>

using namespace std;

char str[][5] = { { "ABCD" },{ "EFGH" },{ "IJKL" },{ "MNOX" } };
char tar[7][7];

int main() {

	int ans = 0;

	for (int i = 0; i < 4; i++)scanf("%s", tar[i]);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int a = 0; a < 4; a++) {
				for (int b = 0; b < 4; b++) {
					if (str[i][j] == tar[a][b]) {
						ans += abs(i - a) + abs(j - b);
					}
				}
			}
		}
	}

	printf("%d\n", ans);

}