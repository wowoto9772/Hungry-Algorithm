#include <stdio.h>

int f[22] = {1, 2, };

int main(){

	for(int i=2; i<=20; i++){
		f[i] = f[i-1] + f[i-2];
	}

	int t;
	scanf("%d", &t);

	while(t--){

		int x;
		scanf("%d", &x);

		int y = 0;

		for(int i=20; i>=1; i--){
			if(x >= f[i]){
				x -= f[i];
				y += f[i-1];
			}
		}

		printf("%d\n", y);

	}


}
