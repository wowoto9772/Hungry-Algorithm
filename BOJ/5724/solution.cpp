#include <stdio.h>

int main(){

	int n;
	while(scanf("%d", &n) == 1){

		if(n == 0)break;

		int c = 0;

		for(int i=1; i<=n; i++){
			c += i*i;
		}

		printf("%d\n", c);

	}

}
