#include <stdio.h>

long long C[20];

int main()
{
	C[0] = 1;
	for (long long i = 1; i <= 19; i++)C[i] = C[i - 1] * i;

	int t;
	scanf("%d", &t);

	while (t--){
		int b, c;
		scanf("%d %d", &b, &c);

		long long ans = 0;
		if (c == 1)ans += C[b - 1];
		else{
			for (long long i = 0; i <= c - 2; i++){
				long long y = C[c - 2] / C[i] / C[c - 2 - i];
				y *= C[i + 1]; // 2 to k permutation
				y *= C[b - 2 - i]; // other permutation
				ans += y;
			}
		}
		printf("%lld\n", ans);
	}
}