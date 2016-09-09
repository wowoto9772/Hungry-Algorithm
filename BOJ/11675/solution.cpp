#include <stdio.h>

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		int x;
		scanf("%d", &x);

		for(int i=0; i<=255; i++){
			if((i^((i<<1)%256)) == x)printf("%d ", i);
		}

	}

}
