#include <stdio.h>

int c[13][13];

int main(){
	c[0][0] = 1;
	for (int i = 1; i <= 10; i++){
		c[i][0] = 1;
		for (int j = 1; j <= i; j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}

	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", c[a][b]);
}