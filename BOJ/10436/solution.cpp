#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int k, a, b;
		scanf("%d %d/%d", &k, &a, &b);

		printf("%d ", k);

		if (b == 1)printf("%d/%d\n", 1, a + 1);
		else if (a < b){
			printf("%d/%d\n", b, b - a);
		}
		else{ // right(m) -> left(n) ==> right(n) -> left(m+1)
			int k = a / b;
			a -= k * b; // left(n)

			// right(n)
			int c = b;
			b = b - a;
			a = c;

			// left(m+1)
			b += a * k;

			printf("%d/%d\n", a, b);
		}
	}
}