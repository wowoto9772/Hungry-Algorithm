#include <stdio.h>

int f[10] = { 1 };

int main() {

	for (int i = 1; i <= 9; i++)f[i] = f[i - 1] * i;

	printf("n e\n");
	printf("- -----------\n");

	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for (int i = 3; i <= 9; i++) {
		double ans = 0;
		for (int j = 0; j <= i; j++)ans += (double)1 / f[j];
		printf("%d %.9lf\n", i, ans);
	}

}