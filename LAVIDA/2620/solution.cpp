#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);

	while (t--){
		long long n, M;
		scanf("%lld", &n);
		M = n;

		for (; n != 1;){
			M = M < n ? n : M;
			if (n % 2)n = n * 3 + 1;
			else
				n /= 2;
		}printf("%lld\n", M);
	}
}