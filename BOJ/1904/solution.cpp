#include <stdio.h>
#define mod 15746

int d[1000003][2];

int main()
{
	d[1][1] = 1; // 1
	d[0][0] = 1; // 00

	for (int i = 2; i <= 1000000; i++){
		d[i][1] = (d[i - 1][0] + d[i - 1][1]) % mod;
		d[i][0] = (d[i - 2][1] + d[i - 2][0]) % mod;
	}

	int n;
	while (scanf("%d", &n) == 1){
		printf("%d\n", (d[n][0] + d[n][1]) % mod);
	}
}