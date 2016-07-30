#include <stdio.h>

int p[2190][2190];
int y[3];

void dnc(int i, int j, int k) {

	int x = p[i][j];

	bool flag = false;
	for (int a = i; !flag && a <= i + k - 1; a++) {
		for (int b = j; !flag && b <= j + k -1; b++) {
			if (x != p[a][b])flag = true;
		}
	}

	if (flag) {

		int nk = k / 3;
		dnc(i, j, nk);
		dnc(i + nk, j, nk);
		dnc(i + 2 * nk, j, nk);

		dnc(i, j + nk, nk);
		dnc(i + nk, j + nk, nk);
		dnc(i + 2 * nk, j + nk, nk);

		dnc(i, j + 2 * nk, nk);
		dnc(i + nk, j + 2 * nk, nk);
		dnc(i + 2 * nk, j + 2 * nk, nk);


	}
	else {
		y[1 + p[i][j]]++;
	}
}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &p[i][j]);
		}
	}

	dnc(1, 1, n);

	for (int i = 0; i < 3; i++)printf("%d\n", y[i]);

}