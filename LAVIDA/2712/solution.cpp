#include <stdio.h>

int main(){

	int n;
	scanf("%d", &n);

	int four = 0, seven = n / 7;

	while (seven >= 0){
		four = (n - seven * 7) / 4;
		if (four * 4 + seven * 7 == n){
			for (int i = 1; i <= four; i++)printf("4");
			for (int i = 1; i <= seven; i++)printf("7");
			printf("\n");
			return 0;
		}
		seven--;
	}

	printf("-1\n");
}