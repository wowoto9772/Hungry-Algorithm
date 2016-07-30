#include <stdio.h>

int I[100];

int GCD(int a, int b){
	int mod = 1;
	while (mod != 0){
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

		int ans = 0;
		for (int i = 1; i <= n; i++)scanf("%d", &I[i]);

		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				ans += GCD(I[i], I[j]);
			}
		}

		printf("%d\n", ans);
	}
}