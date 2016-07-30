#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		bool c[133][133] = { 0 };

		for (int i = 1; i <= n; i++){
			int a, b;
			scanf("%d %d", &a, &b); 

			for (int j = a; j <= a + 9; j++)for (int k = b; k <= b + 9; k++)c[j][k] = true;
		}

		int ans = 0;

		for (int i = 0; i <= 99; i++)for (int j = 0; j <= 99; j++)if (c[i][j])ans++;

		printf("%d\n", ans);
	}
}