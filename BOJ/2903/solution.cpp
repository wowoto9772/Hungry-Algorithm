#include <stdio.h>

int main(){

	int n;
	scanf("%d", &n);

	int p = 1;

	int c = 2;

	for(int i=1; i<=n; i++){
		c += p;
		p <<= 1;
	}

	printf("%d", c*c);


}
