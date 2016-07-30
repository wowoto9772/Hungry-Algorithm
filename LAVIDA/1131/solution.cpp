#include <stdio.h>

int GCD(int a, int b){
	int mod = 1;
	while (mod){
		mod = a % b;
		a = b;
		b = mod;
	}return a;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int S, P;
		int s, p;

		for (int i = 1; i <= n; i++){
			scanf("%d %d", &s, &p);
			if (i == 1)S = s, P = p;
			else{
				S = S*p + s*P;
				P *= p;
				int g = GCD(S, P);
				S /= g;
				P /= g;
			}
		}

		printf("%d/%d\n", S, P);
	}
}