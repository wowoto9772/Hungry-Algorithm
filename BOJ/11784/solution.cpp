#include <stdio.h>

#include <string.h>

char str[503];

int par(int a, int b){
	if(a >= 'A'){
		a = 10 + a - 'A';
	}else{
		a = a - '0';
	}

	if(b >= 'A'){
		b = 10 + b - 'A';
	}else{
		b = b - '0';
	}

	return a * 16 + b;

}

int main(){

	while(scanf("%s", str) == 1){

		int s = strlen(str);

		for(int i=0; i<s; i+=2){
			printf("%c", par(str[i], str[i+1]));
		}

		printf("\n");

	}

}
