#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		printf("%d.", n / m);
		n %= m;

		while (k--){
			n *= 10;
			printf("%d", n/m);
			n %= m;
		}
		printf("\n");
	}
}