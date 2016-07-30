#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int c = 0;

	for (int i = 1; i <= n / 3; i++) {
		for (int j = i; j <= n * 2 / 3; j++) {
			int k = n - i - j;

			if (k < j)break;

			if(k < i+j){
				c++;
			}
		}
	}

	/*
		ntopia

		int ans = 0;
		for (int a = (n - 1) / 2; a >= 1; --a) {
			int c = (n - a) / 2;
			int b = n - a - c;
			if (a - b + 1 <= 0 || c <= 0) {
				break;
			}
			ans += min(a - b + 1, c);
		}

		printf("%d", ans);
	*/

	printf("%d\n", c);

}