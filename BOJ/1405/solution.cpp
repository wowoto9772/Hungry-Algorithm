#include <stdio.h>

bool chk[30][30];

int p[4];

int dtx[] = { 1, -1, 0, 0 };
int dty[] = { 0, 0, -1, 1 };

double ans;

void dy(int c, int x, int y, double pp){

	if (c == 0) {
		ans += pp;
		return;
	}

	for (int i = 0; i < 4; i++) {

  		int nx = x + dtx[i], ny = y + dty[i];

		if (!chk[nx][ny]) {
			chk[nx][ny] = true;
			dy(c - 1, nx, ny, pp * p[i] / 100.0);
			chk[nx][ny] = false;
		}

	}

}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < 4; i++)scanf("%d", &p[i]);

	chk[14][14] = true;
	dy(n, 14, 14, 1.0);

	printf("%.10lf\n", ans);

}