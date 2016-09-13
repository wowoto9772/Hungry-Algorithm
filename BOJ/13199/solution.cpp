#include <stdio.h>

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		int p, m, f, c;
		scanf("%d %d %d %d", &p, &m, &f, &c);

		int a = m / p * c;
		int aa = 0;

		int b = m / p * c;
		int bb = 0;

		while(a >= f){
			aa += a / f;
			a %= f;
		}

		while(b >= f){
			bb += b / f;
			int add = b / f * c;
			b = b % f;
			b += add;
		}

		printf("%d\n", bb-aa);

	}

}
