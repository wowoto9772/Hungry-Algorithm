#include <stdio.h>

int gcd(int a, int b){
	
	int m = 1;

	while(m){
		m = a % b;
		a = b;
		b = m;
	}

	return a;

}


int main(){

	int a,b;
	scanf("%d %d", &a, &b);

	printf("%d\n", a+b-gcd(a,b));

}
