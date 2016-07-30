#include <stdio.h>

int S[13][13], J[13][13], C[13][13];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int a, b;
		scanf("%d %d", &a, &b);

		for (int i = 1; i <= a; i++)for (int j = 1; j <= b; j++)scanf("%d", &S[i][j]);

		int c, d;
		scanf("%d %d", &c, &d);

		for (int i = 1; i <= c; i++)for (int j = 1; j <= d; j++)scanf("%d", &J[i][j]);

		if (b == c && a == d){
			for (int k = 1; k <= a; k++){
				for (int l = 1; l <= d; l++){
					C[k][l] = 0;
					for (int x = 1; x <= b; x++){
						C[k][l] += S[k][x] * J[x][l];
					}
				}
			}
			for (int i = 1; i <= a; i++){
				for (int j = 1; j <= d; j++){
					printf("%d ", C[i][j]);
				}printf("\n");
			}
		}
		else{
			printf("Impossible\n");
		}
	}
}