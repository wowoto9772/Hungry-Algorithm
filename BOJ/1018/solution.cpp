#include <stdio.h>
#include <algorithm>

using namespace std;

char str[53][53];

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	int ans = 64;

	int z[] = { 'W', 'B' };

	for (int a = 0; a < r - 7; a++) {
		for (int b = 0; b < c - 7; b++) {
			int s = (a % 2) ^ (b % 2);
			for (int c = 0; c < 2; c++) {
				int x = 0;
				for (int i = a; i <= a + 7; i++) {
					for (int j = b; j <= b + 7; j++) {
						int k = (i % 2) ^ (j % 2);
						if (s == k) {
							if (z[c] == str[i][j])x++;
						}
						else {
							if (z[c] != str[i][j])x++;
						}
					}
				}
				ans = min(ans, 64 - x);
			}
		}
	}

	printf("%d\n", ans);

}