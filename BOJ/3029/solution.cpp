#include <stdio.h>

int main(){
	int c[3];
	int d[3];
	scanf("%d:%d:%d", &c[0], &c[1], &c[2]);
	scanf("%d:%d:%d", &d[0], &d[1], &d[2]);

	c[2] += 3600 * c[0] + 60 * c[1];
	d[2] += 3600 * d[0] + 60 * d[1];

	d[2] -= c[2];

	if (d[2] < 0)d[2] += 3600 * 24;
	else if (d[2] == 0)d[2] += 24 * 3600;

	printf("%02d:%02d:%02d\n", d[2] / 3600, (d[2] % 3600) / 60, d[2] % 60);
}