#include <stdio.h>

#include <string.h>

char A[33], B[33];

int main(){

	scanf("%s %s", A, B);

	int a = strlen(A), b = strlen(B);

	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			if(A[i] == B[j]){
				int c = 0;
				for(int k=0; k<b; k++){
					if(k == j)printf("%s\n", A);
					else{
						for(int l=0; l<a; l++){
							if(l == i)printf("%c", B[c]);
							else
								printf(".");
						}
						printf("\n");
					}
					c++;
				}
				return 0;
			}
		}
	}

}
