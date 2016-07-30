#include <stdio.h>

void shi(int a[]) {
	int k = a[3];
	for (int i = 2; i >= 0; i--) {
		a[i + 1] = a[i];
	}
	a[0] = k;
}

int main() {

	int a[6];
	scanf("%d %d %d %d", &a[0], &a[1], &a[3], &a[2]);

	double ans = -1;
	int x;
	for (int i = 0; i < 4; i++) {
		double tmp = (double)a[0] / a[3] + (double)a[1] / a[2];
		if (ans < tmp) {
			ans = tmp;
			x = i;
		}
		shi(a);
	}

	printf("%d\n", x);

}