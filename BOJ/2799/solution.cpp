#include <stdio.h>

int ty[] = { 0, 15, 255, 4095, 65535 };
int z[5];

char str[555][555];

int main() {

	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < 5 * m + 1; i++) {
		scanf("%s", str[i]);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int c = 0, x = 0;
			for (int k = i * 5 + 1; k <= i * 5 + 4; k++) {
				for (int l = j * 5 + 1; l <= j * 5 + 4; l++) {
					if (str[k][l] == '*')x += 1 << c;
					c++;
				}
			}
			for (int k = 0; k < 5; k++) {
				if (x == ty[k])z[k]++;
			}
		}
	}

	for (int i = 0; i < 5; i++)printf("%d ", z[i]);

}