#include <stdio.h>

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		int r, c;

		scanf("%d %d", &r, &c);

		printf("1\n");

		for(int i=0; i<c; i++)printf("(%d,%d)\n", 0, i);

		for(int i=1; i<r; i++){
			if(i&1){
				for(int j=c-1; j>=1; j--){
					printf("(%d,%d)\n", i, j);
				}
			}else{
				for(int j=1; j<c; j++){
					printf("(%d,%d)\n", i, j);
				}
			}
		}

		for(int i=r-1; i>=1; i--){
			printf("(%d,0)\n", i, 0);
		}

	}

}
