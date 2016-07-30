#include <stdio.h>

int main() {

	int x[3], y[3], z[3];

	for (int i = 0; i < 3; i++)scanf("%d %d %d", &x[i], &y[i], &z[i]);

	// a2 a3 a1 a2
	// b2 b3 b1 b2

	int vx[2], vy[2], vz[2]; // 2 line's direction vector

	for (int i = 0; i < 2; i++) {
		vx[i] = x[i] - x[i + 1];
		vy[i] = y[i] - y[i + 1];
		vz[i] = z[i] - z[i + 1];
	}

	// vy0 vz0 vx0 vy0
	// vy1 vz1 vx1 vy1

	int a, b, c; // face's normal vector = v1 x v2(outer product)

	a = vy[0] * vz[1] - vz[0] * vy[1];
	b = vz[0] * vx[1] - vx[0] * vz[1];
	c = vx[0] * vy[1] - vy[0] * vx[1];

	int d = -a*x[0] - b*y[0] - c*z[0];

	if (!a && !b && !c)printf("Straight Line\n");
	else {
		printf("%d %d %d %d\n", a, b, c, d);
	}

}