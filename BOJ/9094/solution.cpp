#include <stdio.h>

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int n, m;
		scanf("%d %d", &n, &m);

		int c = 0;
		for (int a = 1; a < n; a++){
			for (int b = a + 1; b < n; b++){
				if ((a*a + b*b + m) / (a*b)*(a*b) == a*a + b*b + m)c++;
			}
		}

		printf("%d\n", c);

	}

}