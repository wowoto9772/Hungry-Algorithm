#include <stdio.h>

int M[12][12];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int m, n;
		scanf("%d %d", &m, &n);

		for (int i = 1; i <= m; i++)for (int j = 1; j <= n; j++)scanf("%d", &M[i][j]);

		int m2, n2;
		scanf("%d %d", &m2, &n2);

		if (m == m2 && n == n2){
			bool f = false;
			for (int i = 1; i <= m; i++){
				for (int j = 1; j <= n; j++){
					int a;
					scanf("%d", &a);
					M[i][j] -= a;
					if (M[i][j])f = true;
				}
			}

			if (!f)printf("Identical\n");
			else{
				for (int i = 1; i <= m; i++){
					for (int j = 1; j <= n; j++){
						printf("%d ", M[i][j]);
					}printf("\n");
				}
			}
		}
		else{
			int a;
			for (int i = 1; i <= m2; i++)for (int j = 1; j <= n2; j++)scanf("%d", &a);
			printf("Impossible\n");
		}
	}
}