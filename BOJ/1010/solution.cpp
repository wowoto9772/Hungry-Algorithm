#include <stdio.h>

#define ll long long

ll c[33][33];

int main(){
	c[0][0] = 1;
	for (int i = 1; i <= 29; i++){
		c[i][0] = 1;
		for (int j = 1; j <= i; j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int b, a;
		scanf("%d %d", &b, &a);
		printf("%lld\n", c[a][b]);
	}
}