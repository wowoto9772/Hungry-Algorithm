#include <stdio.h>

#define dig4(v) v/1000
#define dig3(v) (v%1000)/100
#define dig2(v) (v%100)/10
#define dig(v) v%10

int main(){

	int a, b;
	scanf("%d %d", &a, &b);

	int A[] = { dig4(a), dig3(a), dig2(a), dig(a) };
	int B[] = { dig4(b), dig3(b), dig2(b), dig(b) };

	int c = 0;

	for (int i = 0; i < 4; i++){

		int last = c + A[3 - i] + B[i];
		bool carry = (last >= 10);

		printf("%d", last % 10);

		if (carry){
			c = (last) / 10;
		}
		else
			c = 0;

	}

	printf("\n");
}